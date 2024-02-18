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
    static const int mod = 1000000007;



public:
    int maxOperations(vector<int> &nums)
    {
        map<pair<int, int>, int> mymap;
        int score_1 = nums[0] + nums[1];
        int score_2 = nums[0] + nums[nums.size() - 1];
        int score_3 = nums[nums.size() - 2] + nums[nums.size() - 1];
        int res = 0;
        res = max(res, f(nums, make_pair(0, nums.size() - 1), score_1, mymap));
        if (score_2 != score_1) {
            mymap.clear();
            res = max(res,
                      f(nums, make_pair(0, nums.size() - 1), score_2, mymap));
        }
        if (score_3 != score_2 && score_3 != score_1) {
            mymap.clear();
            res = max(res,
                      f(nums, make_pair(0, nums.size() - 1), score_3, mymap));
        }
        return res;
    }

    int f(vector<int> &nums,
          pair<int, int> interval,
          int score,
          map<pair<int, int>, int> &vec)
    {
        // [start, end]
        int start = interval.first;
        int end = interval.second;
        if (start >= end)
            return 0;
        if (vec.find(interval) != vec.end()) {
            return vec[interval];
        }
        int res = 0;
        if (nums[start] + nums[start + 1] == score) {
            res = max(res, 1 + f(nums, make_pair(start + 2, end), score, vec));
        }
        if (nums[start] + nums[end] == score) {
            res = max(res,
                      1 + f(nums, make_pair(start + 1, end - 1), score, vec));
        }
        if (nums[end - 1] + nums[end] == score) {
            res = max(res, 1 + f(nums, make_pair(start, end - 2), score, vec));
        }
        vec[interval] = res;
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {3, 2, 1, 2, 3, 4};
    vector<int> v2 = {3, 2, 6, 1, 4};
    string s1 = "";
    string t1 = "";
    cout << solver.maxOperations(v1) << endl;
    cout << solver.maxOperations(v2) << endl;
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
