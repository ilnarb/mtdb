#include <tbb/concurrent_hash_map.h>
#include <iostream>

const int SIZE = 1000000;

int main()
{
   tbb::concurrent_hash_map<int,int> map;
   map.rehash(2*SIZE);
   //
   long long c = 0;
   for (int i = 0; i < SIZE; ++i)
   {
      // c += m[i*i] += i;
      tbb::concurrent_hash_map<int,int>::accessor a;
      map.insert(a, i*i);
      c += a->second += i;
   }
   //
   std::cout << c << std::endl;
   return 0;
}
