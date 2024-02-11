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
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    vector<int> build(vector<int> &patterns)
    {
        vector<int> res = {0, 0};
        int j = 0;
        for (int i = 1; i < patterns.size(); i++) {
            while (j > 0 && patterns[i] != patterns[j]) {
                j = res[j];
            }
            if (patterns[i] == patterns[j]) {
                j++;
            }
            res.push_back(j);
        }
        return res;
    }

public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &patterns)
    {
        vector<int> next = build(patterns);
        // print_vector(next);
        vector<int> idxs;
        vector<int> numsp;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                numsp.push_back(1);
            } else if (nums[i] < nums[i - 1]) {
                numsp.push_back(-1);
            } else {
                numsp.push_back(0);
            }
        }

        int j = 0;
        for (int i = 0; i < numsp.size(); i++) {
            while (j > 0 && numsp[i] != patterns[j]) {
                j = next[j];
            }
            if (numsp[i] == patterns[j]) {
                j++;
            }
            if (j == patterns.size()) {
                idxs.push_back(i - j + 1);
                j = next[j];
            }
        }
        return idxs.size();
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<int> p1 = {1, 1};
    vector<int> v2 = {1, 4, 4, 1, 3, 5, 5, 3};
    vector<int> p2 = {1, 0, -1};
    cout << solver.countMatchingSubarrays(v1, p1) << endl;
    cout << solver.countMatchingSubarrays(v2, p2) << endl;
    return 0;

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
