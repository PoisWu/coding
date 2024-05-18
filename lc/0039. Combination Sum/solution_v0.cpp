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
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

    void dfs(vector<vector<int>> &res,
             vector<int> &cur,
             vector<int> nums,
             int target,
             int pos)
    {
        for (int i = pos; i < nums.size(); i++) {
            if (nums[i] > target)
                continue;
            if (nums[i] == target) {
                cur.push_back(nums[i]);
                res.push_back(cur);
                cur.pop_back();
            } else {
                cur.push_back(nums[i]);
                dfs(res, cur, nums, target - nums[i], i);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // try use recursive
        // dp[i] = combinationSum(condidate, target)
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, candidates, target, 0);
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {2, 3, 6, 7};
    print_2d_vector(solver.combinationSum(v1, 7));
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
