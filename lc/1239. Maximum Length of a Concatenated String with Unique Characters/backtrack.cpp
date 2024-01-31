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
private:
    bool overlap(unordered_set<char> charset, string &s)
    {
        for (auto c : s) {
            if (charset.count(c))
                return true;
            charset.insert(c);
        }
        return false;
    }
    int backtrack(unordered_set<char> &charset, vector<string> &arr, int i)
    {
        if (i == (int) arr.size()) {
            return charset.size();
        }
        int res = 0;
        if (!overlap(charset, arr[i])) {
            for (auto c : arr[i]) {
                charset.insert(c);
            }
            res = backtrack(charset, arr, i + 1);
            for (auto c : arr[i]) {
                charset.erase(c);
            }
        }
        res = max(res, backtrack(charset, arr, i + 1));

        return res;
    }

public:
    int maxLength(vector<string> &arr)
    {
        unordered_set<char> charset;
        return backtrack(charset, arr, 0);
    }
};
