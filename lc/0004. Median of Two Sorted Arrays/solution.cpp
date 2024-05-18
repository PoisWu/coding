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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total % 2) {
            // odd
            return findkth(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            // 4
            // 1 2 3
            double tmp = findkth(nums1, 0, nums2, 0, total / 2);
            tmp += findkth(nums1, 0, nums2, 0, total / 2 + 1);
            return tmp / 2;
        }
    }

    double findkth(vector<int> &nums1, int a, vector<int> &nums2, int b, int k)
    {
        // [.... x x x x x]
        //       ^_ ath
        // 0 1 2 3 4 5 6
        int m = nums1.size();
        int n = nums2.size();

        if (m - a > n - b) {
            return findkth(nums2, b, nums1, a, k);
        }
        if (m - a == 0) {
            return (double) nums2[b + k - 1];
        }

        if (k == 1) {
            return (double) min(nums1[a], nums2[b]);
        }

        int k1 = min(k / 2, m - a);
        int k2 = k - k1;
        // k1+ k2 = k

        if (nums1[a + k1 - 1] < nums2[b + k2 - 1]) {
            return findkth(nums1, a + k1, nums2, b, k - k1);
        } else {
            return findkth(nums1, a, nums2, b + k2, k - k2);
        }
    }
};



int main()
{
    Solution solver;
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout << solver.findMedianSortedArrays(v1, v2) << endl;
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
