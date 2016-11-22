#include <tbb/concurrent_queue.h>
#include <unordered_map>
#include <iostream>
#include <future>
#include <thread>

const int SIZE = 1000000;

struct shard_t
{
   std::unordered_map<int,int> map;
   tbb::concurrent_queue<int> queue;
   std::future<long long> fu;
   char pad[64];
};

int main(int argc, char *argv[])
{
   const int thcount = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 1;
   // assume data sharded by %thcount between threads
   shard_t shards[thcount];
   for (int k = 0; k < thcount; k++)
   {
      auto &s = shards[k];
      s.map.reserve(2*SIZE/thcount);
      s.fu = std::async(std::launch::async, [&](int kk)-> long long
      {
         auto &s = shards[kk];
         long long c = 0;
         int i = -1;
         do
         {
            if (s.queue.try_pop(i))
            {
               if (i < 0) break;
               c += s.map[i*i] += i;
            }
         }
         while(true);
         return c;
      }, k);
   }
   // emulate requests
   for (int i = 0; i < SIZE; i++)
      shards[unsigned(i*i) % thcount].queue.push(i);
   // done
   for (auto &s : shards)
      s.queue.push(-1);
   // merge result
   long long c = 0;
   for (auto &s : shards)
      c += s.fu.get();
   //
   std::cout << c << std::endl;
   return 0;
}
