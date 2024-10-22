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
    int maxProduct(vector<int> &nums)
    {
        int ret = nums[0];
        long long pos = 0;
        long long neg = 0;
        if (nums[0] > 0) {
            pos = nums[0];
        } else {
            neg = nums[0];
        }
        nums.erase(nums.begin());
        for (auto x : nums) {
            long long tmp_pos = pos;
            long long tmp_neg = neg;
            if (x == 0) {
                pos = 0;
                neg = 0;
            } else if (x > 0) {
                if (tmp_pos == 0) {
                    pos = x;
                } else {
                    pos = x * tmp_pos;
                }
                neg = x * tmp_pos;

            } else if (x < 0) {
                if (tmp_pos == 0) {
                    neg = x;
                } else {
                    neg = x * tmp_pos;
                }
                pos = tmp_neg * x;
            }
            ret = max(pos, ret);
            ret = max(neg, ret);
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v2 = {2, 3, -2, 4};
    vector<int> v1 = {-2, 0, -1};
    string s1 = "";
    string t1 = "";
    cout << solver.maxProduct(v1) << endl;
    cout << solver.maxProduct(v2) << endl;
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
