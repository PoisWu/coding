#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    int row;
    int col;
    int dp[70][70][70];

    int f(int r1, int r2, int r, vector<vector<int>> &grid)
    {
        if (r >= row || r1 < 0 || r1 >= col || r2 < 0 || r2 >= col) {
            return 0;
        }

        if (dp[r1][r2][r] != -1) {
            return dp[r1][r2][r];
        }

        int ans;
        if (r1 == r2) {
            ans = grid[r][r1];
        } else {
            ans = grid[r][r1] + grid[r][r2];
        }
        int nxt = 0;
        for (int nxtr1 : {r1 - 1, r1, r1 + 1}) {
            for (int nxtr2 : {r2 - 1, r2, r2 + 1}) {
                nxt = max(nxt, f(nxtr1, nxtr2, r + 1, grid));
            }
        }
        ans = ans + nxt;
        dp[r1][r2][r] = ans;
        return ans;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        memset(dp, -1, sizeof(dp));

        // (robot 1, robot 2, row) => cols*cols*row

        return f(0, col - 1, 0, grid);
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({3, 1, 1});
    v1.push_back({2, 5, 1});
    v1.push_back({1, 5, 5});
    v1.push_back({2, 1, 1});

    vector<vector<int>> v2 = {};
    v2.push_back({1, 0, 0, 0, 0, 0, 1});
    v2.push_back({2, 0, 0, 0, 0, 3, 0});
    v2.push_back({2, 0, 9, 0, 0, 0, 0});
    v2.push_back({0, 3, 0, 5, 4, 0, 0});
    v2.push_back({1, 0, 2, 3, 0, 0, 6});
    string s1 = "";
    string t1 = "";
    // cout << solver.cherryPickup(v1) << endl;
    // cout << solver.cherryPickup(v2) << endl;
    vector<vector<int>> v3 = {};
    v3.push_back({8, 8, 10, 9, 1, 7});
    v3.push_back({8, 8, 1, 8, 4, 7});
    v3.push_back({8, 6, 10, 3, 7, 7});
    v3.push_back({3, 0, 9, 3, 2, 7});
    v3.push_back({6, 8, 9, 4, 2, 5});
    v3.push_back({1, 1, 5, 8, 8, 1});
    v3.push_back({5, 6, 5, 2, 9, 9});
    v3.push_back({4, 4, 6, 2, 5, 4});
    v3.push_back({4, 4, 5, 3, 1, 6});
    v3.push_back({9, 2, 2, 1, 9, 3});
    cout << solver.cherryPickup(v3) << endl;
    vector<vector<int>> v4 = {};
    v4.push_back({0, 8, 7, 10, 9, 10, 0, 9, 6});
    v4.push_back({8, 7, 10, 8, 7, 4, 9, 6, 10});
    v4.push_back({8, 1, 1, 5, 1, 5, 5, 1, 2});
    v4.push_back({9, 4, 10, 8, 8, 1, 9, 5, 0});
    v4.push_back({4, 3, 6, 10, 9, 2, 4, 8, 10});
    v4.push_back({7, 3, 2, 8, 3, 3, 5, 9, 8});
    v4.push_back({1, 2, 6, 5, 6, 2, 0, 10, 0});
    cout << solver.cherryPickup(v4) << endl;
    // print_vector(solver.);
    return 0;

    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    // TreeNode two = TreeNode(2);
    // TreeNode nine = TreeNode(9);
    // TreeNode four = TreeNode(4, &nine, &two);
    // TreeNode five = TreeNode(5, NULL, &four);
    // TreeNode ten = TreeNode(10);
    // TreeNode six = TreeNode(6);
    // TreeNode three = TreeNode(3, &ten, &six);
    // TreeNode one = TreeNode(1, &five, &three);
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
