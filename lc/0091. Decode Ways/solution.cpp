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
    vector<int> dp;

public:
    int numDecodings(string s)
    {
        int n = s.length();

        dp = vector<int>(n + 1, -1);
        dp[0] = 1;
        return dfs(s, n);
    }
    int dfs(string s, int pos)
    {
        if (pos == 0) {
            return dp[0];
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int tmp = 0;
        if (pos >= 1 && s[pos - 1] != '0') {
            tmp += dfs(s, pos - 1);
        }
        if (pos >= 2) {
            int a = stoi(s.substr(pos - 2, 2));
            if (a <= 26 && a >= 10)
                tmp += dfs(s, pos - 2);
        }
        dp[pos] = tmp;
        return dp[pos];
    }
};

int main()
{
    Solution solver;
    cout << solver.numDecodings("12") << endl;
    cout << solver.numDecodings("226") << endl;
    cout << solver.numDecodings("06") << endl;
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
