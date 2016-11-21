#include "mpmc_bounded_queue.h"
#include <unordered_map>
#include <iostream>
#include <future>
#include <thread>

const int SIZE = 1000000;

inline int shard(int i, int thcount)
{
   return ((unsigned)i*(unsigned)i) % thcount;
//   return ((unsigned)i) % thcount;
}

typedef std::unordered_map<int,int> map_t;
typedef mpmc_bounded_queue<int> queue_t;

int main(int argc, char *argv[])
{
   const int thcount = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 1;
   // assume data sharded by %thcount between threads
   map_t maps[thcount];
   queue_t queues[thcount];
   std::future<long long> fu[thcount];
   for (int k = 0; k < thcount; k++)
   {
      maps[k].reserve(2*SIZE);
      fu[k] = std::async(std::launch::async, [&](int kk)-> long long
      {
         auto &m = maps[kk];
         auto &queue = queues[kk];
         long long c = 0;
         int i = -1;
         do
         {
            if (queue.try_pop(i))
            {
               if (i < 0) break;
               c += m[i*i] += i;
            }
         }
         while(true);
         return c;
      }, k);
   }
   // emulate requests
   for (int i = 0; i < SIZE; i++)
      queues[shard(i, thcount)].push(i);
   // done
   for (int k=0; k<thcount; k++)
      queues[k].push(-1);
   // merge result
   long long c = 0;
   for (int k = 0; k < thcount; k++)
      c += fu[k].get();
   //
   std::cout << c << std::endl;
}
