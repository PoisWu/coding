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


using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

public:
    vector<int> largestDivisibleSubset(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> tree;
        int n = nums.size();
        pair<int, int> dp[n];  // prev, length
        int max_num = 1;
        int max_idx = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0) {
                    tree[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int pre = -1;
            int tmp_max = 1;
            for (auto x : tree[i]) {
                int tmp = dp[x].second + 1;
                if (tmp > tmp_max) {
                    tmp_max = tmp;
                    pre = x;
                }
            }
            if (tmp_max > max_num) {
                max_num = tmp_max;
                max_idx = i;
            }
            dp[i] = make_pair(pre, tmp_max);
        }

        vector<int> res(max_num, 0);
        int pacour = max_idx;

        for (int i = 0; i < max_num; i++) {
            res[max_num - 1 - i] = nums[pacour];
            pacour = dp[pacour].first;
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 4, 8};
    vector<int> v2 = {1, 2, 3};
    print_vector(solver.largestDivisibleSubset(v1));
    print_vector(solver.largestDivisibleSubset(v2));
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
