#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
void print_2d_vector(vector<vector<T>> vvec)
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
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        vector<long long> presum(nums.size(), 0);
        unordered_map<int, vector<int>> map;  // value, list of idx position
        presum[0] = nums[0];
        map[nums[0]].push_back(0);
        long long res = LLONG_MIN;
        bool isfound = false;
        for (int i = 1; i < nums.size(); i++) {
            presum[i] = nums[i] + presum[i - 1];
            map[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (auto idx : map[nums[i] - k]) {
                if (idx < i) {
                    res = max(res, presum[i] - (idx > 0 ? presum[idx - 1] : 0));
                    isfound = true;
                }
            }
            for (auto idx : map[nums[i] + k]) {
                if (idx < i) {
                    res = max(res, presum[i] - (idx > 0 ? presum[idx - 1] : 0));
                    isfound = true;
                }
            }
        }
        if (!isfound) {
            return 0;
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {-1, -2, -3, -4};
    cout << solver.maximumSubarraySum(v1, 1) << endl;
    cout << solver.maximumSubarraySum(v2, 2) << endl;
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
