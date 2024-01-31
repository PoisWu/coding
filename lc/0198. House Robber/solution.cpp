#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int dp[n];
        // dp[i] store how much money can still from [0,i] must pick nums[i]
        dp[0] = nums[0];
        for (long unsigned int i = 1; i < nums.size(); i++) {
            if (i == 1) {
                dp[i] = nums[1];
            }
            if (i == 2) {
                dp[i] = dp[i - 2] + nums[i];
            }
            if (i >= 3) {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            }
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};
