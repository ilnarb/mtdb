#include <tbb/concurrent_hash_map.h>
#include <iostream>
#include <future>
#include <thread>

const int SIZE = 1000000;

int main(int argc, char *argv[])
{
   const int thcount = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 1;
   //
   tbb::concurrent_hash_map<int,int> map;
   map.rehash(2*SIZE);
   //
   std::future<long long> fu[thcount];
   for (int k = 0; k < thcount; k++)
   {
      fu[k] = std::async(std::launch::async, [&](int kk)-> long long
      {
         long long c = 0;
         for (int i = kk; i < SIZE; i += thcount)
         {
            // c += m[i*i] += i;
            tbb::concurrent_hash_map<int,int>::accessor a;
            map.insert(a, i*i);
            c += a->second += i;
         }
         return c;
      }, k);
   }
   //
   long long c = 0;
   for (int k = 0; k < thcount; k++)
      c += fu[k].get();
   //
   std::cout << c << std::endl;
   return 0;
}
