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
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ret = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ret++;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ret++;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; (i + len - 1) < n; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ret++;
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.countSubstrings("abc") << endl;
    cout << solver.countSubstrings("aaa") << endl;
    cout << solver.countSubstrings(
                "cdddddcbadcbbaabdcabbcbdbbccabccbbabadccdbbddddacdbdacadaadddd"
                "dc")
         << endl;
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
