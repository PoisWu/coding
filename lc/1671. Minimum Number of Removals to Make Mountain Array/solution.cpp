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
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> arr;
        arr.clear();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            if (it == arr.end()) {
                arr.push_back(nums[i]);
                left[i] = arr.size();
            } else {
                *it = nums[i];
                left[i] = distance(arr.begin(), it) + 1;
            }
        }
        arr.clear();
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            if (it == arr.end()) {
                arr.push_back(nums[i]);
                right[i] = arr.size();
            } else {
                *it = nums[i];
                right[i] = distance(arr.begin(), it) + 1;
            }
        }

        int maxLen = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i] >= 2 && right[i] >= 2) {
                maxLen = max(maxLen, left[i] + right[i] - 1);
            }
        }
        return n - maxLen;
    }
};
int main()
{
    Solution solver;
    vector<int> v1 = {100, 92, 89, 77, 74, 66, 64, 66, 64};
    string s1 = "";
    string t1 = "";
    cout << solver.minimumMountainRemovals(v1) << endl;
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
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
