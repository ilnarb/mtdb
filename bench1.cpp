#include <unordered_map>
#include <iostream>

const int SIZE = 1000000;

int main()
{
   std::unordered_map<int,int> map;
   map.reserve(2*SIZE);
   //
   long long c = 0;
   for (int i = 0; i < SIZE; ++i)
      c += map[i*i] += i;
   //
   std::cout << c << std::endl;
   return 0;
}
