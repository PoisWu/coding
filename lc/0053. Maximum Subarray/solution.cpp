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

public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1) {
            return nums[0];
        }
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1; i < n; i++) {
            if (dp[i - 1] < 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i - 1] + nums[i];
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solver.maxSubArray(v1) << endl;
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
