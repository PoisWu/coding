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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> bufp;
        queue<TreeNode *> bufq;
        bufp.push(p);
        bufq.push(q);
        while (!bufp.empty()) {
            if (bufq.empty()) {
                return false;
            }
            TreeNode *nodep = bufp.front();
            TreeNode *nodeq = bufq.front();
            bufp.pop();
            bufq.pop();
            if (nodep == NULL || nodeq == NULL) {
                if (nodep != NULL)
                    return false;
                if (nodeq != NULL)
                    return false;
            } else {
                if (nodep->val != nodeq->val) {
                    return false;
                } else {
                    bufp.push(nodep->left);
                    bufp.push(nodep->right);
                    bufq.push(nodeq->left);
                    bufq.push(nodeq->right);
                }
            }
        }
        if (!bufq.empty()) {
            return false;
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
    // cout << solver.<< endl;
    // print_vector(solver.);
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
