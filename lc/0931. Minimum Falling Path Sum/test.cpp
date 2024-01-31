#include <iostream>
#include <vector>
#include "solution.cpp"
using namespace std;
template <typename T>
void print_2d_vector(vector<vector<T>> vvec)
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
    vector<int> v1 = {2, 1, 3};
    vector<int> v2 = {6, 5, 4};
    vector<int> v3 = {7, 8, 9};
    vector<vector<int>> v = {v1, v2, v3};
    cout << solver.minFallingPathSum(v) << endl;
}
