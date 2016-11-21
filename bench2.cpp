#include <tbb/concurrent_unordered_map.h>
#include <iostream>

const int SIZE = 1000000;

typedef tbb::concurrent_unordered_map<int, int> map_t;

int main()
{
   map_t map;
   map.rehash(2*SIZE);
   //
   long long c = 0;
   for (int i = 0; i < SIZE; ++i)
      c += map[i*i] += i;
   //
   std::cout << c << std::endl;
}
