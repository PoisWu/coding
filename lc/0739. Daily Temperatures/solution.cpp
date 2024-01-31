#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
    static const int mod = 1000000007;

public:
    vector<int> dailyTemperatures(vector<int> &v)
    {
        int n = v.size();
        vector<int> out(n, 0);
        // pair of <val, idx>
        stack<pair<int, int> > buf;

        for (int i = 0; i < n; i++) {
            if (buf.empty() || buf.top().first >= v[i]) {
                buf.push(make_pair(v[i], i));
            } else {
                while (!buf.empty() && buf.top().first < v[i]) {
                    out[buf.top().second] = i - buf.top().second;
                    buf.pop();
                }
                buf.push(make_pair(v[i], i));
            }
        }
        return out;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {73, 74, 75, 71, 69, 72, 76, 73};
    print_vector(solver.dailyTemperatures(v1));

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
}
