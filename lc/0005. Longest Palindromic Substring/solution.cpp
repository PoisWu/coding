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
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    string longestPalindrome(string t)
    {
        string s = "#";
        for (char c : t) {
            s.push_back(c);
            s += "#";
        }
        int reach = -1;
        int center = -1;
        int n = s.length();
        int maxlen = -1;
        int maxpos = -1;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            // X [X X X X . a . X o X X] X X X X X
            int r = 0;
            if (i <= reach) {
                r = min(dp[2 * center - i], reach - i);
            }
            while (i + r < n && i - r >= 0 && s[i + r] == s[i - r]) {
                r++;
            }
            dp[i] = r - 1;
            if (reach < dp[i] + i) {
                reach = dp[i] + i;
                center = i;
            }
            if (maxlen < 2 * dp[i] + 1) {
                maxlen = 2 * dp[i] + 1;
                maxpos = i - dp[i];
            }
        }
        return t.substr(maxpos / 2, maxlen / 2);
    }
};

int main()
{
    Solution solver;
    string s1 = "babad";
    string t1 = "cbbd";
    cout << solver.longestPalindrome(s1) << endl;
    cout << solver.longestPalindrome(t1) << endl;
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
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
