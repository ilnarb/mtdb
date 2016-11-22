#include <unordered_map>
#include <iostream>
#include <future>
#include <thread>
#include <mutex>

const int SIZE = 1000000;

int main(int argc, char *argv[])
{
   const int thcount = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 1;
   //
   std::unordered_map<int,int> map;
   map.reserve(2*SIZE);
   //
   std::mutex mutex;
   std::future<long long> fu[thcount];
   for (int k = 0; k < thcount; k++)
   {
      fu[k] = std::async(std::launch::async, [&](int kk)-> long long
      {
         long long c = 0;
         for (int i = kk; i < SIZE; i += thcount)
         {
            std::lock_guard<std::mutex> l(mutex);
            c += map[i*i] += i;
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
