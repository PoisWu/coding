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
private:
    static const int mod = 1000000007;

    void changedir(int &x, int &y)
    {
        if (x == 0 && y == 1) {
            x = 1;
            y = 0;
        } else if (x == 1 && y == 0) {
            x = 0;
            y = -1;
        } else if (x == 0 && y == -1) {
            x = -1;
            y = 0;
        } else if (x == -1 && y == 0) {
            x = 0;
            y = 1;
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // m * n matrix
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        int h_step = n - 1;
        int v_step = m - 1;

        for (int i = 0; i < n; i++) {
            res.push_back(matrix[0][i]);
        }
        int x = 0;
        int y = n - 1;
        int dx = 1;
        int dy = 0;
        bool direction_v = true;
        while ((direction_v && v_step > 0) || (!direction_v && h_step > 0)) {
            if (direction_v) {
                for (int i = 0; i < v_step; i++) {
                    x += dx;
                    y += dy;
                    res.push_back(matrix[x][y]);
                }
                v_step--;
            } else {
                for (int i = 0; i < h_step; i++) {
                    x += dx;
                    y += dy;
                    res.push_back(matrix[x][y]);
                }
                h_step--;
            }
            changedir(dx, dy);
            direction_v = !direction_v;
        }
        return res;
    }
};

// 6*4 m = 6,
// 5r -> 3d -> 5l -> 2u -> 4r -> 1d -> 3l
// 5 5 4 3 2 1
// 4 3 2 1

int main()
{
    Solution solver;
    vector<vector<int>> v2 = {};
    v2.push_back({1, 2, 3, 4});
    v2.push_back({5, 6, 7, 8});
    v2.push_back({9, 10, 11, 12});
    print_vector(solver.spiralOrder(v2));
    // vector<vector<int>> v1 = {};
    // v1.push_back({1,2,3});
    // v1.push_back({4,5,6});
    // v1.push_back({7,8,9});
    // print_vector(solver.spiralOrder(v1));
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
