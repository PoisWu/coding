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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }
        bool ret = false;
        if (root->val == subRoot->val) {
            ret = ret || (isSame(root->left, subRoot->left) &&
                          isSame(root->right, subRoot->right));
        }
        if (ret)
            return true;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL) {
            return root1 == root2;
        }
        return root1->val == root2->val && isSame(root1->right, root2->right) &&
               isSame(root1->left, root2->left);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.<< endl;
    print_vector(solver.);
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
