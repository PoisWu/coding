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
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int res = 0;
        int mul = 1;
        while (n != 0) {
            if (n >= 8) {
                res += mul * 8;
                mul++;
                n -= 8;
            } else {
                res += mul * n;
                n = 0;
            }
        }
        return res;
    }
};
