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

public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> fifo;
        fifo.push(root);
        bool isEven = false;
        while (!fifo.empty()) {
            int n = fifo.size();
            if (isEven) {
                int pre = INT_MAX;
                for (int i = 0; i < n; i++) {
                    TreeNode *node = fifo.front();
                    fifo.pop();
                    if (node) {
                        if (node->val % 2 != 0 || node->val >= pre) {
                            return false;
                        }
                        pre = node->val;
                        fifo.push(node->left);
                        fifo.push(node->right);
                    }
                }
                isEven = false;
            } else {
                int pre = INT_MIN;
                for (int i = 0; i < n; i++) {
                    TreeNode *node = fifo.front();
                    fifo.pop();
                    if (node) {
                        if (node->val % 2 == 0 || node->val <= pre) {
                            return false;
                        }
                        pre = node->val;
                        fifo.push(node->left);
                        fifo.push(node->right);
                    }
                }
                isEven = true;
            }
        }
        return true;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
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
