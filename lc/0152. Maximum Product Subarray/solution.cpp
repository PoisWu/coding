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
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> p_dp(n, 0);
        vector<int> n_dp(n, 0);
        int rets = nums[0];
        if (nums[0] > 0) {
            p_dp[0] = nums[0];
        } else {
            n_dp[0] = nums[0];
        }

        for (int i = 1; i < n; i++) {
            int x = nums[i];
            if (x > 0) {
                p_dp[i] = (p_dp[i - 1] != 0) ? p_dp[i - 1] * x : x;
                n_dp[i] = (n_dp[i - 1] != 0) ? n_dp[i - 1] * x : 0;

            } else if (x == 0) {
                p_dp[i] = 0;
                n_dp[i] = 0;
            } else {
                p_dp[i] = (n_dp[i - 1] != 0) ? n_dp[i - 1] * x : 0;
                n_dp[i] = (p_dp[i - 1] != 0) ? p_dp[i - 1] * x : x;
            }
            rets = max(rets, p_dp[i]);
            rets = max(rets, n_dp[i]);
        }
        return rets;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {2, 3, -2, 4};
    vector<int> v2 = {-2, 0, -1};
    vector<int> v3 = {3, -1, 4};
    string s1 = "";
    string t1 = "";
    cout << solver.maxProduct(v1) << endl;
    cout << solver.maxProduct(v2) << endl;
    cout << solver.maxProduct(v3) << endl;
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
