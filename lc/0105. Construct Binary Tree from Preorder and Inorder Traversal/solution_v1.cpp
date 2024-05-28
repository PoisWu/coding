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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, 0, inorder, 0, inorder.size());
    }
    TreeNode *helper(vector<int> &preorder,
                     int ix,
                     vector<int> &inorder,
                     int jx,
                     int jy)
    {
        // [x, y[
        if (jx == jy) {
            return NULL;
        }
        int val_node = preorder[ix];
        int j;
        for (j = jx; j < jy; j++) {
            if (inorder[j] == val_node) {
                break;
            }
        }
        TreeNode *root = new TreeNode(val_node);
        root->left = helper(preorder, ix + 1, inorder, jx, j);
        root->right = helper(preorder, ix + j - jx + 1, inorder, j + 1, jy);
        return root;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {3, 9, 20, 15, 7};
    vector<int> v2 = {9, 3, 15, 20, 7};
    string s1 = "";
    string t1 = "";
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
