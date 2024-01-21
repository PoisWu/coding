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
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {2, 7, 9, 3, 1};
    cout << solver.rob(v1) << endl;
    cout << solver.rob(v2) << endl;
}
