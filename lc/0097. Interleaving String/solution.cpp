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
    vector<vector<vector<int>>> dp;

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        dp = vector<vector<vector<int>>>(
            l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(l3 + 1, -1)));
        dp[0][0][0] = 1;
        return helper(s1, l1, s2, l2, s3, l3);
    }
    // dp[i][j][k] whether s1[0...i] s2[0...j] can build s3[0...k]
    bool helper(string s1, int i, string s2, int j, string s3, int k)
    {
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        if (i + j != k) {
            dp[i][j][k] = 0;
            return dp[i][j][k];
        }

        char c = s3[k - 1];
        int tmp = 0;
        if (i >= 1 && c == s1[i - 1]) {
            tmp = tmp | helper(s1, i - 1, s2, j, s3, k - 1);
        }
        if (j >= 1 && c == s2[j - 1]) {
            tmp = tmp | helper(s1, i, s2, j - 1, s3, k - 1);
        }
        dp[i][j][k] = tmp;
        return dp[i][j][k];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    cout << solver.isInterleave("a", "b", "ab") << endl;
    cout << solver.isInterleave("acc", "b", "acbc") << endl;
    cout << solver.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
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
