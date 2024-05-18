#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
using lli = long long int;

template <typename T>
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int row = 0;
        int start = 0;
        int end = n - 2;
        while (start <= end) {
            for (int j = start; j <= end; j++) {
                int x0 = row;
                int y0 = j;
                int x1 = y0;
                int y1 = n - 1 - x0;
                int x2 = y1;
                int y2 = n - 1 - x1;
                int x3 = y2;
                int y3 = n - 1 - x2;
                swap(matrix[x0][y0], matrix[x1][y1]);
                swap(matrix[x3][y3], matrix[x0][y0]);
                swap(matrix[x2][y2], matrix[x3][y3]);
            }
            row++;
            start++;
            end--;
        }
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 2, 3});
    v1.push_back({4, 5, 6});
    v1.push_back({7, 8, 9});
    solver.rotate(v1);
    print_2d_vector(v1);
    return 0;
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

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
