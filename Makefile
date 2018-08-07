objects=build/simulation.o build/material.o
CFLAGS=-Wall -Wextra -std=c++11

SMIDGE: $(objects)
	g++ $(CFLAGS) $(objects) src/main.cpp -o SMIDGE

.PHONY: clean
clean:
	-rm build/* SMIDGE tests

.PHONY: run
run: SMIDGE
	./SMIDGE

tests: $(objects)
	g++ $(CFLAGS) -I libs/boost_1_67_0 -I src $(objects) test/tests.cpp -o tests

.PHONY: runTest
runTest: tests
	./tests

$(objects): build/%.o : src/%.cpp src/%.h
	g++ $(CFLAGS) -c $< -o $@
