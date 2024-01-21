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
    vector<int> v1 = {2, 4, 6, 8, 10};
    vector<int> v2 = {7, 7, 7, 7, 7};
    cout << solver.numberOfArithmeticSlices(v1) << endl;
    cout << solver.numberOfArithmeticSlices(v2) << endl;
}
