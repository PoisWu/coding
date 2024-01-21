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
    int minimumCost(vector<int> &nums)
    {
        int m1 = nums[0];
        int m2 = 51;
        int m3 = 51;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < m2) {
                m3 = m2;
                m2 = nums[i];
            } else if (nums[i] < m3) {
                m3 = nums[i];
            }
        }
        return m1 + m2 + m3;
    }
};
