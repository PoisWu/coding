#include <iostream>
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
    cout << "start" << endl;
    string w10 = "abc";
    string w11 = "bca";
    string w20 = "cabbba";
    string w21 = "abbccc";
    cout << solver.closeStrings(w10, w11) << endl;
    cout << solver.closeStrings(w20, w21) << endl;
}
