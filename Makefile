objects=build/simulation.o
CFLAGS=-Wall

SMIDGE: $(objects)
	g++ $(CFLAGS) $(objects) src/main.cpp -o SMIDGE

.PHONY: clean
clean:
	-rm build/* SMIDGE tests

.PHONY: run
run: SMIDGE
	./SMIDGE

tests: $(objects)
	g++ $(CFLAGS) -I libs/boost_1_67_0 $(objects) test/tests.cpp -o tests

.PHONY: runTest
runTest: tests
	./tests

$(objects): build/%.o : src/%.cpp
	g++ $(CFLAGS) -c $^ -o $@
