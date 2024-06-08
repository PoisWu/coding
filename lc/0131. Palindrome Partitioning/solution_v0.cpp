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
    bool dp[16][16];
    vector<vector<string>> rets;
    vector<string> ans;
    vector<vector<string>> partition(string s)
    {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                dp[i][j] = false;
            }
        }
        rets.clear();
        ans.clear();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1];
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; (i + len - 1) < n; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                }
            }
        }
        dfs(0, n, s);
        return rets;
    }
    void dfs(int cur, int n, string s)
    {
        if (cur == n) {
            rets.push_back(ans);
            return;
        }
        for (int i = cur; i < n; i++) {
            if (dp[cur][i]) {
                ans.push_back(s.substr(cur, i - cur + 1));
                dfs(i + 1, n, s);
                ans.pop_back();
            }
        }
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    print_2d_vector(solver.partition("aab"));
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
