#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
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

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


class Solution
{
private:
    bool ispp(unordered_set<int> &freq) { return freq.size() <= 1; }
    void dfs(TreeNode *node, int &res, unordered_set<int> &freq)
    {
        int val = node->val;
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if (freq.count(val)) {
            freq.erase(val);
        } else {
            freq.insert(val);
        }
        if (left || right) {
            // node is not the leaf
            if (right) {
                dfs(right, res, freq);
            }
            if (left) {
                dfs(left, res, freq);
            }
        } else {
            if (ispp(freq)) {
                res++;
            }
        }
        if (freq.count(val)) {
            freq.erase(val);
        } else {
            freq.insert(val);
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_set<int> freq;
        // dfs
        int res = 0;
        dfs(root, res, freq);
        return res;
    }
};

int main()
{
    Solution solver;

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
    // TreeNode two = TreeNode(2);
    // TreeNode nine = TreeNode(9);
    // TreeNode four = TreeNode(4, &nine, &two);
    // TreeNode five = TreeNode(5, NULL, &four);
    // TreeNode ten = TreeNode(10);
    // TreeNode six = TreeNode(6);
    // TreeNode three = TreeNode(3, &ten, &six);
    // TreeNode one = TreeNode(1, &five, &three);
    //
}
