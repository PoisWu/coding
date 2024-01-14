#include <algorithm>
#include <iostream>
#include <map>
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
    bool halvesAreAlike(string s)
    {
        int n = s.length();
        map<char, int> freq;
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return std::tolower(c); });


        for (int i = 0; i < n; i++) {
            freq[s[i]] = freq[s[i]] + 1 * (i >= n / 2 ? -1 : 1);
        }
        return !(freq['a'] + freq['e'] + freq['i'] + freq['o'] + freq['u']);
    };
};
