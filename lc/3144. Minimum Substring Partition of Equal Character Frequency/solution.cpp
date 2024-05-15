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
private:
    static const int mod = 1000000007;

    vector<int> dp;

public:
    int minimumSubstringsInPartition(string s)
    {
        dp.resize(s.length(), -1);
        int ret = helper(s, s.length() - 1);
        print_vector(dp);
        return ret;
    }

    int helper(string s, int i)
    {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i == 0) {
            return dp[0] = 1;
        }
        vector<int> freq(26, 0);
        unordered_set<char> taken;
        int res = INT_MAX;
        for (int j = i; j >= 0; j--) {
            freq[s[j] - 'a']++;
            taken.insert(s[i]);
            int f = freq[s[j] - 'a'];
            bool canbreak = true;
            for (auto c : taken) {
                if (freq[c - 'a'] != f) {
                    canbreak = false;
                    break;
                }
            }
            if (canbreak) {
                cout << i << " " << j << endl;
                print_vector(freq);
                res = min(j - 1 >= 0 ? helper(s, j - 1) + 1 : 1, res);
            }
        }
        dp[i] = res;
        return dp[i];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "fabccddg";
    // string s2 = "abababaccddb";
    cout << solver.minimumSubstringsInPartition(s1) << endl;
    // cout << solver.minimumSubstringsInPartition(s2)<< endl;
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
