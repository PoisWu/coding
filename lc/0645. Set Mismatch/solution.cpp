#include <algorithm>
#include <array>
#include <cstring>
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
public:
    vector<int> findErrorNums(vector<int> nums)
    {
        int n = nums.size();
        int freq[n];  //[0, n-1]
        for (int i = 0; i < n; i++) {
            freq[i] = 0;
        }
        for (auto x : nums) {
            freq[x - 1]++;
        }

        int dup = -1;
        int miss = -1;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                miss = i + 1;
            }
            if (freq[i] == 2) {
                dup = i + 1;
            }
        }
        return {dup, miss};
    }
};
