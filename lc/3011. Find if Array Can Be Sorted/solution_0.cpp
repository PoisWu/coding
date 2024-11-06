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
    bool canSortArray(vector<int> &nums)
    {
        for (long unsigned int i = 0; i < nums.size(); i++) {
            for (long unsigned int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j] && __builtin_popcount(nums[i]) !=
                                             __builtin_popcount(nums[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
