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
    bool searchMatrix(vector<vector<int>> &matrix, int t)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] < t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int x = l / n;
        int y = l % n;
        return t == matrix[x][y];
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 3, 5, 7});
    v1.push_back({10, 11, 16, 20});
    v1.push_back({23, 30, 34, 60});
    cout << solver.searchMatrix(v1, 3) << endl;
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
