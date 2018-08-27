objects=build/simulation.o build/material.o build/surface.o build/plane.o
CFLAGS=-Wall -Wextra -std=c++11 -g

SMIDGE: $(objects) build/main.o
	g++ $(CFLAGS) $^ -o SMIDGE

.PHONY: clean
clean:
	-rm build/* SMIDGE tests

.PHONY: run
run: SMIDGE
	./SMIDGE

tests: $(objects) build/tests.o
	g++ $(CFLAGS) $^ -o tests

.PHONY: runTests
runTests: tests
	./tests

$(objects): build/%.o : src/%.cpp src/%.h
	g++ $(CFLAGS) -c $< -o $@

build/tests.o: test/tests.cpp
	g++ $(CFLAGS) -I libs/boost_1_67_0 -I src -c $< -o $@

build/main.o: src/main.cpp
	g++ $(CFLAGS) -c $< -o $@
