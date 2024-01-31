#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

class Solution
{
    static const int mod = 1000000007;
    static long long aux(vector<int> &arr, long long start, long long end)
    {
        // Find the min between [start, end]
        // Compute the sum
        if (start == end) {
            return (long long) arr[(int) start];
        }
        long long res = 0;
        long long idx_min = start;
        long long val_min = arr[(int) start];
        for (long long i = start; i <= end; i++) {
            if (arr[(int) i] < val_min) {
                idx_min = i;
                val_min = arr[(int) i];
            }
        }

        res = ((idx_min - start + 1) * (end - idx_min + 1) *
               (long long) val_min) %
              mod;
        // cout << "val_min " << val_min << endl;
        // cout << "start " << start << endl;
        // cout << "end " << end << endl;
        // cout << "res "   << res << endl;


        if (idx_min > start) {
            res = (res + aux(arr, start, idx_min - 1)) % mod;
        }
        if (idx_min < end) {
            res = (res + aux(arr, idx_min + 1, end)) % mod;
        }
        return res;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        return (int) aux(arr, 0, arr.size() - 1);
    }
};
