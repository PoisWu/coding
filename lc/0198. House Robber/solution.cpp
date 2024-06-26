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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        if (n == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }


        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];

        int rets = max(dp[2], dp[1]);

        for (int i = 3; i < n; i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            rets = max(rets, dp[i]);
        }
        return rets;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {2, 7, 9, 3, 1};
    vector<int> v2 = {100, 1, 1, 100};
    cout << solver.rob(v1) << endl;
    cout << solver.rob(v2) << endl;
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
