OPTS=-std=c++11 -O3 -ltcmalloc

all: bench1 bench1mt bench1mtfg bench2 bench2mt bench3 bench3mt mtdb mtdb2
clean:
	rm -f bench1 bench1mt bench1mtfg bench2 bench2mt bench3 bench3mt mtdb mtdb2

bench1: bench1.cpp
	$(CXX) $(OPTS) $< -o $@
bench1mt: bench1mt.cpp
	$(CXX) $(OPTS) $< -o $@ -pthread
bench1mtfg: bench1mtfg.cpp
	$(CXX) $(OPTS) $< -o $@ -pthread
bench2: bench2.cpp
	$(CXX) $(OPTS) $< -o $@ -ltbb
bench2mt: bench2mt.cpp
	$(CXX) $(OPTS) $< -o $@ -ltbb
bench3: bench3.cpp
	$(CXX) $(OPTS) $< -o $@ -ltbb
bench3mt: bench3mt.cpp
	$(CXX) $(OPTS) $< -o $@ -ltbb
mtdb: mtdb.cpp
	$(CXX) $(OPTS) $< -o $@ -ltbb
mtdb2: mtdb2.cpp
	$(CXX) $(OPTS) $< -o $@ -pthread
