#include <unordered_map>
#include <iostream>
#include <future>
#include <thread>
#include <mutex>

const int SIZE = 1000000;

struct data_t
{
   std::unordered_map<int,int> map;
   std::mutex mutex;
   char pad[64];
   data_t()
   {
      map.reserve(2*SIZE/100);
   }
};
data_t& data(unsigned n)
{
   static data_t datas[100];
   return datas[n % 100];
}

int main(int argc, char *argv[])
{
   const int thcount = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 1;
   //
   std::future<long long> fu[thcount];
   for (int k = 0; k < thcount; k++)
   {
      fu[k] = std::async(std::launch::async, [&](int kk)-> long long
      {
         long long c = 0;
         for (int i = kk; i < SIZE; i += thcount)
         {
            data_t &d = data(i*i);
            std::lock_guard<std::mutex> l(d.mutex);
            c += d.map[i*i] += i;
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
