CXX      := g++
# CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
CXXFLAGS := -Wall -Wextra -g
SRC      := solution.cpp 

OBJECTS  := $(SRC:%.cpp=%.o)


main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: 
	./main

clean:
	-@rm -rvf ./*.o
	-@rm -rvf ./main

