#include <iostream>
#include <vector>
#include "solution.cpp"
using namespace std;
// template <typename T>
// void print_2d_vector(vector<vector<T> > vvec)
// {
//     for (auto vec : vvec) {
//         for (auto e : vec) {
//             cout << e << " ";
//         }
//         cout << endl;
//     }
// }

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    Solution solver;
    cout << "start" << endl;
    print_vector(solver.countOfPairs(3, 1, 3));
}
