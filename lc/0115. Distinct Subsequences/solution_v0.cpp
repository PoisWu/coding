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
    vector<vector<int>> dp;
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        s = "#" + s;
        t = "#" + t;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 0;
        }
        return dfs(s, t, m, n);
    }
    int dfs(string s, string t, int i, int j)
    {
        if (i < j) {
            dp[i][j] = 0;
            return dp[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            dp[i][j] = dfs(s, t, i - 1, j - 1) + dfs(s, t, i - 1, j);
        } else {
            dp[i][j] = dfs(s, t, i - 1, j);
        }
        return dp[i][j];
    }
};
int main()
{
    Solution solver;
    cout << solver.numDistinct("rabbbit", "rabbit") << endl;
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
