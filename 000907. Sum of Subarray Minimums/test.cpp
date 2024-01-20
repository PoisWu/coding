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
    vector<int> v1 = {3, 1, 2, 4};
    vector<int> v2 = {11, 81, 94, 43, 3};
    cout << solver.sumSubarrayMins(v1) << endl;
    cout << solver.sumSubarrayMins(v2) << endl;
}
