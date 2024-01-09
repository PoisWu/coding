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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaf1;
        vector<TreeNode *> heap;
        heap.push_back(root1);
        while (!heap.empty()) {
            TreeNode *node = heap.back();
            heap.pop_back();
            if (node) {
                TreeNode *left = node->left;
                TreeNode *right = node->right;
                if (left || right) {
                    heap.push_back(left);
                    heap.push_back(right);
                } else {
                    leaf1.push_back(node->val);
                }
            }
        }

        heap.push_back(root2);
        int idx = 0;
        bool isSame = true;
        while (!heap.empty()) {
            TreeNode *node = heap.back();
            heap.pop_back();
            if (node) {
                TreeNode *left = node->left;
                TreeNode *right = node->right;
                if (left || right) {
                    heap.push_back(left);
                    heap.push_back(right);
                } else {
                    if (leaf1[idx] == node->val) {
                        idx++;
                    } else {
                        isSame = false;
                        break;
                    }
                }
            }
        }
        isSame = isSame && (idx == leaf1.size());
        return isSame;
    }
};
