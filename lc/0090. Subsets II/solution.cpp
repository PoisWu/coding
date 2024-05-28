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
    vector<int> curr;
    vector<vector<int>> ret;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        curr.clear();
        ret.clear();
        sort(nums.begin(), nums.end());
        dfs(nums, 0, true);
        return ret;
    }
    void dfs(vector<int> &nums, int pos, bool pretaken)
    {
        if (pos == nums.size()) {
            ret.push_back(curr);
            return;
        }
        if (pretaken || nums[pos - 1] != nums[pos]) {
            curr.push_back(nums[pos]);
            dfs(nums, pos + 1, true);
            curr.pop_back();
        }
        dfs(nums, pos + 1, false);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 2, 1};
    string s1 = "";
    string t1 = "";
    print_2d_vector(solver.subsetsWithDup(v1));
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
