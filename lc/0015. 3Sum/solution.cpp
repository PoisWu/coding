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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        // suppose nums[i] <= nums[j] <= nums[k]
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {0, 0, 0};
    vector<int> v2 = {-1, 0, 1, 2, -1, -4};
    print_2d_vector(solver.threeSum(v1));
    print_2d_vector(solver.threeSum(v2));
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
