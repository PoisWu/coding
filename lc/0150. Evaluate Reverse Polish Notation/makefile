CXX      := g++
# CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
# CXXFLAGS := -Wall -Wextra -g -fsanitize=address
CXXFLAGS := -Wall -Wextra -g 
SRC      := solution.cpp 


main: solution.cpp
	$(CXX) $(CXXFLAGS) -o main $^ 

run: 
	./main

clean:
	-@rm -rvf ./*.o
	-@rm -rvf ./main

