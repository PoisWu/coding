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

    vector<vector<int>> tabp;
    vector<vector<int>> taba;
    int m;
    int n;

public:
    void dfsp(vector<vector<int>> &heights, int i, int j, int h)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || tabp[i][j] != 0)
            return;
        if (h <= heights[i][j]) {
            tabp[i][j] = 1;
            h = heights[i][j];
            dfsp(heights, i + 1, j, h);
            dfsp(heights, i - 1, j, h);
            dfsp(heights, i, j + 1, h);
            dfsp(heights, i, j - 1, h);
        }
    }

    void dfsa(vector<vector<int>> &heights, int i, int j, int h)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || taba[i][j] != 0)
            return;
        if (h <= heights[i][j]) {
            taba[i][j] = 1;
            h = heights[i][j];
            dfsa(heights, i + 1, j, h);
            dfsa(heights, i - 1, j, h);
            dfsa(heights, i, j + 1, h);
            dfsa(heights, i, j - 1, h);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        tabp.resize(m, vector<int>(n, 0));
        taba.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfsp(heights, i, 0, heights[i][0]);          // left
            dfsa(heights, i, n - 1, heights[i][n - 1]);  // left
        }
        for (int j = 0; j < n; j++) {
            dfsp(heights, 0, j, heights[0][j]);          // left
            dfsa(heights, m - 1, j, heights[m - 1][j]);  // left
        }
        vector<vector<int>> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (taba[i][j] && tabp[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 2, 2, 3, 5});
    v1.push_back({3, 2, 3, 4, 4});
    v1.push_back({2, 4, 5, 3, 1});
    v1.push_back({6, 7, 1, 4, 5});
    v1.push_back({5, 1, 1, 2, 4});
    print_2d_vector(solver.pacificAtlantic(v1));
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
