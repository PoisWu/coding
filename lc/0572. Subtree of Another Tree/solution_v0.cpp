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
    bool equalTree(TreeNode *a, TreeNode *b)
    {
        if (a == NULL || b == NULL) {
            return a == b;
        }

        return a->val == b->val && equalTree(a->left, b->left) &&
               equalTree(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (equalTree(root, subRoot))
            return true;

        if (root == NULL) {
            return subRoot == NULL;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
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
