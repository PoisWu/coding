#include <algorithm>
#include <iostream>
#include <map>
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int res = 0;
        vector<TreeNode *> heap;
        heap.push_back(root);
        while (!heap.empty()) {
            TreeNode *node = heap.back();
            heap.pop_back();
            if (node) {
                int val = node->val;
                if (val <= high && val >= low) {
                    res += val;
                }
                heap.push_back(node->left);
                heap.push_back(node->right);
            }
        }
        return res;
    }
};
