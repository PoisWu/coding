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
    cout << solver.climbStairs(3) << endl;
    cout << solver.climbStairs(2) << endl;
    cout << solver.climbStairs(4) << endl;
}
