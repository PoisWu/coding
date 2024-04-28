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


class Solution
{
private:
    static const int mod = 1000000007;


    TreeNode *buildTree(vector<int> &preorder,
                        vector<int> &inorder,
                        int pre_i,
                        int pre_j,
                        int in_i,
                        int in_j)
    {
        // preorder: center, left, right
        // inorder left, center, right
        // preorder = [] inordfer = [] => nullptr
        // preorder = [a] inorder = [a] => TreeNode(a);
        // [pre_i, pre_j]
        // [in_i, in_j]
        if (pre_j < pre_i || in_j < in_i) {
            return nullptr;
        }
        int center_val = preorder[pre_i];
        TreeNode *node = new TreeNode(center_val);
        // find index of center in in_j;
        int in_center;
        for (int i = in_i; i <= in_j; i++) {
            if (inorder[i] == center_val) {
                in_center = i;
                break;
            }
        }
        int l = in_center - 1 - in_i;
        node->left = buildTree(preorder, inorder, pre_i + 1, l + pre_i + 1,
                               in_i, in_center - 1);
        node->right = buildTree(preorder, inorder, l + pre_i + 2, pre_j,
                                in_center + 1, in_j);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int len = preorder.size();
        return buildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {3, 9, 20, 15, 7};
    vector<int> v2 = {9, 3, 15, 20, 7};
    cout << solver.buildTree(v1, v2) << endl;
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
