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

    int maxDownSum(TreeNode *root, int &rets)
    {
        if (root == NULL)
            return 0;

        int rightSum = maxDownSum(root->right, rets);
        int leftSum = maxDownSum(root->left, rets);
        int sum = root->val;

        if (rightSum > 0)
            sum += rightSum;
        if (leftSum > 0)
            sum += leftSum;

        rets = max(sum, rets);



        if (rightSum < 0 && leftSum < 0)
            return root->val;

        return root->val + max(rightSum, leftSum);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int rets = INT_MIN;
        maxDownSum(root, rets);
        return rets;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    TreeNode two = TreeNode(2);
    TreeNode nine = TreeNode(9);
    TreeNode four = TreeNode(4, &nine, &two);
    TreeNode five = TreeNode(5, NULL, &four);
    TreeNode ten = TreeNode(10);
    TreeNode six = TreeNode(6);
    TreeNode three = TreeNode(3, &ten, &six);
    TreeNode one = TreeNode(1, &five, &three);
    cout << solver.maxPathSum(&one) << endl;
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
