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
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == NULL)
            return 0;

        int left = INT_MIN / 2;
        int right = INT_MAX / 2;
        // 0 1
        // mid = 0

        while (left < right) {
            int mid = left + (right - left) / 2;
            int r = findsmaller(root, mid);
            if (r >= k) {
                // there are r element in tree smaller or equal to mid
                // if r > k -> mid is to big
                // left mid right
                // k = 2
                // left 1     mid     right
                // x  mid y
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int findsmaller(TreeNode *root, int num)
    {
        // find nb of node smaller than or equal to num
        if (root == NULL) {
            return 0;
        }
        if (root->val <= num) {
            return 1 + findsmaller(root->right, num) +
                   findsmaller(root->left, num);
        } else {
            return findsmaller(root->left, num);
        }
    }
};

int main()
{
    Solution solver;
    TreeNode *root = new TreeNode(1);
    cout << solver.kthSmallest(root, 1) << endl;
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
