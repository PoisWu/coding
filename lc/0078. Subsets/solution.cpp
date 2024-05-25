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
    vector<vector<int>> ret;
    vector<int> curr;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        ret.clear();
        curr.clear();
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int> &nums, int idx)
    {
        if (idx == nums.size()) {
            ret.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        dfs(nums, idx + 1);
        curr.pop_back();
        dfs(nums, idx + 1);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3};
    print_2d_vector(solver.subsets(v1));
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
