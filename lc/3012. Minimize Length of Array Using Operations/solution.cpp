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
    int minimumArrayLength(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int cou = 0;
        for (auto x : nums) {
            if (x % smallest) {
                return 1;
            }
            if (x == smallest) {
                cou++;
            }
        }
        return cou / 2 + cou % 2;
    }
};
