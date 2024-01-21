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
    vector<int> v1 = {1, 2, 3, 12};
    vector<int> v2 = {5, 4, 3};
    vector<int> v3 = {10, 3, 1, 1};
    cout << solver.minimumCost(v1) << endl;
    cout << solver.minimumCost(v2) << endl;
    cout << solver.minimumCost(v3) << endl;
}
