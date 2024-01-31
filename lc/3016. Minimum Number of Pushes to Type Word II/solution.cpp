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
        int arr[26] = {0};
        int n = word.length();
        for (int i = 0; i < n; i++) {
            arr[word[i] - 'a']++;
        }
        sort(arr, arr + 26);
        int res = 0;
        int quota = 8;
        int mul = 1;
        for (int i = 25; i >= 0; i--) {
            if (arr[i] != 0) {
                res += mul * arr[i];
                quota--;
                if (quota == 0) {
                    mul++;
                    quota = 8;
                }
            } else {
                break;
            }
        }
        return res;
    }
};
