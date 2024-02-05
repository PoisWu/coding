CXX      := g++
# CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
CXXFLAGS := -Wall -Wextra -g

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main $^ 

run: 
	./main < in.txt

clean:
	-@rm -rvf ./*.o
	-@rm -rvf ./main

