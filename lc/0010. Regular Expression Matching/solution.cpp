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
    bool isMatch(string s, string p)
    {
        // dp [i][j]
        // s[0:i]
        // p[0:j] match
        int m = s.length();
        int n = p.length();
        s = "#" + s;
        p = "#" + p;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= n; j++) {
            dp[0][j] = p[j] == '*' && dp[0][j - 2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j] == '*') {
                    bool possible1 = dp[i][j - 2];
                    bool possible2 =
                        (p[j - 1] == '.' || s[i] == p[j - 1]) && dp[i - 1][j];
                    dp[i][j] = possible1 || possible2;
                } else if (p[j] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = (p[j] == s[i] && dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    cout << solver.isMatch("aa", "a") << endl;
    cout << solver.isMatch("aa", "a*") << endl;
    cout << solver.isMatch("ab", "ab") << endl;
    cout << solver.isMatch("", "") << endl;
    cout << solver.isMatch("ab", "..") << endl;
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
