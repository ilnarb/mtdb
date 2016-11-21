all: bench1 bench1mt bench2 bench2mt bench3 bench3mt mtdb mtdb2
clean:
	rm -f bench1 bench1mt bench2 bench2mt bench3 bench3mt mtdb mtdb2

bench1: bench1.cpp
	$(CXX) -std=c++11 -O3 $< -o $@
bench1mt: bench1mt.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -pthread
bench2: bench2.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -ltbb
bench2mt: bench2mt.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -ltbb
bench3: bench3.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -ltbb
bench3mt: bench3mt.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -ltbb
mtdb: mtdb.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -ltbb
mtdb2: mtdb2.cpp
	$(CXX) -std=c++11 -O3 $< -o $@ -pthread
