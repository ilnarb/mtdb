# mtdb
Bench MT maps and MT DB concept

bench1 - initial single thread std::unordered_map w/o locks
real    0m0.235s
user    0m0.211s
sys     0m0.024s

multithreaded std::unordered_map w/ mutex
bench1mt 1
real    0m0.915s
user    0m0.850s
sys     0m1.709s
bench1mt 2
real    0m0.322s
user    0m0.290s
sys     0m0.032s
bench1mt 4
real    0m0.877s
user    0m0.847s
sys     0m1.725s
bench1mt 8
real    0m1.453s
user    0m1.062s
sys     0m8.406s
bench1mt 16
real    0m1.202s
user    0m0.840s
sys     0m7.990s

bench2 - single thread tbb::concurrent_unordered_map w/ embed locks
real    0m0.497s
user    0m0.469s
sys     0m0.029s

multithreaded tbb::concurrent_unordered_map w/ embed locks
bench2mt 1
real    0m0.553s
user    0m0.516s
sys     0m0.038s
bench2mt 2
real    0m0.414s
user    0m0.632s
sys     0m0.045s
bench2mt 4
real    0m0.291s
user    0m0.690s
sys     0m0.071s
bench2mt 8
real    0m0.271s
user    0m1.240s
sys     0m0.121s
bench2mt 16
real    0m0.308s
user    0m1.530s
sys     0m0.190s

bench2 - single thread tbb::concurrent_hash_map w/ embed locks
bench3
real    0m0.496s
user    0m0.456s
sys     0m0.041s

multithreaded tbb::concurrent_hash_map w/ embed locks
bench3mt 1
real    0m0.593s
user    0m0.548s
sys     0m0.046s
bench3mt 2
real    0m0.413s
user    0m0.519s
sys     0m0.045s
bench3mt 4
real    0m0.326s
user    0m0.665s
sys     0m0.045s
bench3mt 8
real    0m0.313s
user    0m1.204s
sys     0m0.045s
bench3mt 16
real    0m0.306s
user    0m1.281s
sys     0m0.048s

multithreaded DB concept w/ data sharded between threads
std::unordered_map is used as a data map and tbb::concurrent_queue as channel between "network" and "db engine" threads
mtdb 1
real    0m0.363s
user    0m0.439s
sys     0m0.044s
mtdb 2
real    0m0.318s
user    0m0.703s
sys     0m0.049s
mtdb 4
real    0m0.346s
user    0m1.199s
sys     0m0.070s
mtdb 8
real    0m0.334s
user    0m1.282s
sys     0m0.101s
mtdb 16
real    0m0.637s
user    0m3.617s
sys     0m0.216s

multithreaded DB concept w/ data sharded between threads
std::unordered_map is used as a data map and lock-free mpmc_bounded_queue as a channel between "network" and "db engine" threads
mtdb2 1
real    0m0.359s
user    0m0.612s
sys     0m0.026s
mtdb2 2
real    0m0.223s
user    0m0.478s
sys     0m0.031s
mtdb2 4
real    0m0.255s
user    0m0.812s
sys     0m0.061s
mtdb2 8
real    0m0.372s
user    0m1.930s
sys     0m0.093s
mtdb2 16
real    0m0.561s
user    0m3.065s
sys     0m0.205s
