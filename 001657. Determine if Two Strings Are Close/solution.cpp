#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
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
    bool closeStrings(string w1, string w2)
    {
        if (w1.length() != w2.length())
            return false;

        array<int, 26> freq1{};
        array<int, 26> freq2{};

        for (long unsigned int i = 0; i < w1.length(); i++) {
            freq1[w1[i] - 'a']++;
            freq2[w2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((bool) freq1[i] != (bool) freq2[i]) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
