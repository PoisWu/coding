#include <iostream>
#include <vector>
#include "2610.cpp"
using namespace std;

void print_2d_vector(vector<vector<int> > vec)
{
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution solver;
    cout << "start" << endl;

    vector<int> v1{1, 3, 4, 1, 2, 3, 1};
    vector<int> v2{2, 1, 1};
    vector<int> v3{8, 8, 8, 8, 2, 4, 4, 2, 4};
    print_2d_vector(solver.findMatrix(v1));
    print_2d_vector(solver.findMatrix(v2));
    print_2d_vector(solver.findMatrix(v3));
}
