#include <iostream>
#include <string>
#include <vector>
#include "solution.cpp"
using namespace std;
template <typename T>
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution solver;
    string s = "book";
    string s2 = "textbook";
    cout << "start" << endl;
    cout << solver.halvesAreAlike(s) << endl;
    cout << solver.halvesAreAlike(s2) << endl;
}
