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
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 1) {
            return nums;
        }
        vector<int> ret;
        ret.resize(0);
        int start = 0;
        int end = start + 1;
        while (start < n - k + 1) {
            while (end < n && nums[end] == nums[end - 1] + 1) {
                end++;
            }
            if (end - start >= k) {
                ret.push_back(nums[start + k - 1]);
            } else {
                ret.push_back(-1);
            }
            start++;
            if (end == start) {
                end++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 4, 3, 2, 5};
    string s1 = "";
    string t1 = "";
    print_vector(solver.resultsArray(v1, 3));
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
