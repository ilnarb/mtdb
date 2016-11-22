# mtdb
Bench MT maps and MT DB concept

bench1
initial single thread std::unordered_map without locks

banch1mt
naive multithreaded std::unordered_map with mutex locks

bench1mtfg
multithreaded std::unordered_map with fine grained mutex locks

bench2
single thread tbb::concurrent_unordered_map with embed locks

bench2mt
multithreaded tbb::concurrent_unordered_map with embed locks

bench3
single thread tbb::concurrent_hash_map with embed locks

bench3mt
multithreaded tbb::concurrent_hash_map with embed locks

mtdb
multithreaded DB concept with data sharded between threads
std::unordered_map as a data map and tbb::concurrent_queue as a channel between "network" and "db engine" threads

mtdb2
multithreaded DB concept with data sharded between threads
std::unordered_map as a data map and lock-free mpmc_bounded_queue as a channel between "network" and "db engine" threads
