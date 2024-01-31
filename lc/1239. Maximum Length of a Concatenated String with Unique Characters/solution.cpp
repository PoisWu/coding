#include <algorithm>
#include <array>
#include <bitset>
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
    int maxLength(vector<string> &arr)
    {
        // using bitset
        unordered_set<char> charset;

        vector<bitset<26>> unique;
        for (auto s : arr) {
            bitset<26> bin;
            for (auto ch : s) {
                bin.set(ch - 'a');
            }
            if (bin.count() == s.length()) {
                unique.push_back(bin);
            }
        }

        vector<bitset<26>> concat = {bitset<26>()};
        int max_length = 0;
        for (auto u : unique) {
            for (int i = concat.size() - 1; i >= 0; i--) {
                if ((concat[i] & u).none()) {
                    concat.push_back(u | concat[i]);
                    // last add element;
                    max_length = max(max_length, (int) concat.back().count());
                }
            }
        }
        return max_length;
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"un", "iq", "ue"};
    vector<string> v2 = {"char", "r", "act", "ers"};
    vector<string> v3 = {"abcdefghijklmnopqrstuvwxy",
                         "ab",
                         "cd",
                         "ef",
                         "gh",
                         "ij",
                         "kl",
                         "mn",
                         "op",
                         "qr",
                         "st",
                         "uv",
                         "wx",
                         "yz"};
    vector<string> v4 = {"aa", "bb"};
    vector<string> v5 = {"jnfbyktlrqumowxd", "mvhgcpxnjzrdei"};
    cout << solver.maxLength(v1) << endl;
    cout << solver.maxLength(v2) << endl;
    cout << solver.maxLength(v3) << endl;
    cout << solver.maxLength(v4) << endl;
    cout << solver.maxLength(v5) << endl;
}
