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
    vector<int> ret;
    vector<vector<int>> rets;

public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int t)
    {
        rets.clear();
        ret.clear();
        sort(nums.begin(), nums.end());
        dfs(nums, t, 0, true);
        return vector<vector<int>>(rets.begin(), rets.end());
    }
    void dfs(vector<int> &nums, int t, int idx, bool pre)
    {
        if (t == 0) {
            rets.push_back(ret);
            return;
        }
        if (idx == nums.size()) {
            return;
        }

        if (nums[idx] <= t) {
            if (idx == 0 || nums[idx - 1] != nums[idx] || pre) {
                ret.push_back(nums[idx]);
                dfs(nums, t - nums[idx], idx + 1, true);
                ret.pop_back();
            }
        }
        dfs(nums, t, idx + 1, false);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {10, 1, 2, 7, 6, 1, 5};
    string s1 = "";
    string t1 = "";
    print_2d_vector(solver.combinationSum2(v1, 8));
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
