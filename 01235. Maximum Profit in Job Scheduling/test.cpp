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
    vector<int> start = {1, 2, 3, 3};
    vector<int> end = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    cout << solver.jobScheduling(start, end, profit) << endl;
    vector<int> start2 = {1, 2, 3, 4, 6};
    vector<int> end2 = {3, 5, 10, 6, 9};
    vector<int> profit2 = {20, 20, 100, 70, 60};
    cout << solver.jobScheduling(start2, end2, profit2) << endl;

    vector<int> start3 = {1, 1, 1};
    vector<int> end3 = {2, 3, 4};
    vector<int> profit3 = {5, 6, 4};
    cout << solver.jobScheduling(start3, end3, profit3) << endl;
}
