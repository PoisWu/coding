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
public:
    vector<int> ret;
    vector<vector<int>> rets;
    vector<vector<int>> combinationSum(vector<int> &nums, int t)
    {
        dfs(nums, t, 0);
        return rets;
    }
    void dfs(vector<int> &nums, int t, int idx)
    {
        if (t == 0) {
            rets.push_back(ret);
            return;
        }
        if (idx == nums.size()) {
            return;
        }
        if (nums[idx] <= t) {
            ret.push_back(nums[idx]);
            dfs(nums, t - nums[idx], idx);
            ret.pop_back();
        }
        dfs(nums, t, idx + 1);
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
