CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Werror=return-type  -Werror=uninitialized # --coverage
# Do not allow compiling if a non-void function is missing a return statement
# Do not allow compiling if a variable is used without being initialized

SRCS = $(wildcard src/*.hpp)
OBJECTS = $(SRCS:src/%.hpp=src/%.o)

CATCH = test/catch/catch.o
TEST_SRCS = $(wildcard test/*.cpp)
TESTS = $(TEST_SRCS:test/%.cpp=%)

main: $(OBJECTS) src/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-all: $(TESTS)
test-catch: test/test-catch.cpp
test-two-strings-retriever: test/test-two-strings-retriever.cpp src/two-strings-retriever.o
test-lcs-solver: test/test-lcs-solver.cpp src/two-strings-retriever.o src/lcs-solver.o
test-multi-strings-retriever: test/test-multi-strings-retriever.cpp src/multi-strings-retriever.o

clean:
	rm -rf *.dSYM
	rm -rf test/*.dSYM
	$(RM) src/*.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main $(CATCH)