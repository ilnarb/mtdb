# benchmarks
Server: 2 * Intel(R) Xeon(R) CPU E5-2609 0 @ 2.40GHz
* Cores: 2*4, no HT
* http://ark.intel.com/products/64588/Intel-Xeon-Processor-E5-2609-10M-Cache-2_40-GHz-6_40-GTs-Intel-QPI

## bench1
real    0m0.190s
user    0m0.170s
sys     0m0.020s

## bench1mt
### 1
real    0m0.241s
user    0m0.224s
sys     0m0.017s
### 2
real    0m0.393s
user    0m0.328s
sys     0m0.219s
### 4
real    0m0.806s
user    0m0.749s
sys     0m1.679s
### 8
real    0m1.065s
user    0m0.851s
sys     0m6.379s
### 16
real    0m0.959s
user    0m0.647s
sys     0m6.463s
### 32
real    0m0.971s
user    0m0.710s
sys     0m6.554s

## bench1mtfg
### 1
real    0m0.340s
user    0m0.310s
sys     0m0.030s
### 2
real    0m0.197s
user    0m0.253s
sys     0m0.022s
### 4
real    0m0.188s
user    0m0.317s
sys     0m0.055s
### 8
real    0m0.203s
user    0m0.396s
sys     0m0.104s
### 16
real    0m0.178s
user    0m0.375s
sys     0m0.122s
### 32
real    0m0.191s
user    0m0.423s
sys     0m0.170s

## bench2
real    0m0.492s
user    0m0.448s
sys     0m0.044s

## bench2mt
### 1
real    0m0.497s
user    0m0.460s
sys     0m0.037s
### 2
real    0m0.333s
user    0m0.499s
sys     0m0.041s
### 4
real    0m0.288s
user    0m0.693s
sys     0m0.062s
### 8
real    0m0.297s
user    0m1.415s
sys     0m0.113s
### 16
real    0m0.276s
user    0m1.251s
sys     0m0.181s
### 32
real    0m0.312s
user    0m1.382s
sys     0m0.342s

## bench3
real    0m0.499s
user    0m0.458s
sys     0m0.042s

## bench3mt
### 1
real    0m0.591s
user    0m0.542s
sys     0m0.049s
### 2
real    0m0.418s
user    0m0.534s
sys     0m0.040s
### 4
real    0m0.294s
user    0m0.539s
sys     0m0.046s
### 8
real    0m0.318s
user    0m1.178s
sys     0m0.045s
### 16
real    0m0.315s
user    0m1.246s
sys     0m0.083s
### 32
real    0m0.315s
user    0m1.200s
sys     0m0.095s

## mtdb
### 1
real    0m0.364s
user    0m0.576s
sys     0m0.026s
### 2
real    0m0.334s
user    0m0.875s
sys     0m0.026s
### 4
real    0m0.335s
user    0m1.411s
sys     0m0.038s
### 8
real    0m0.269s
user    0m1.725s
sys     0m0.025s
### 16
real    0m0.184s
user    0m0.817s
sys     0m0.030s
### 32
real    0m0.286s
user    0m1.789s
sys     0m0.031s

## mtdb2
### 1
real    0m0.279s
user    0m0.469s
sys     0m0.019s
### 2
real    0m0.159s
user    0m0.331s
sys     0m0.025s
### 4
real    0m0.159s
user    0m0.503s
sys     0m0.026s
### 8
real    0m0.158s
user    0m0.725s
sys     0m0.024s
### 16
real    0m0.168s
user    0m0.766s
sys     0m0.030s
### 32
real    0m0.219s
user    0m1.086s
sys     0m0.049s
