#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
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

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;
        unordered_set<char> chars;
        for (char &c : s) {
            freq_s[c]++;
            chars.insert(c);
        }

        for (char &c : t) {
            freq_t[c]++;
            chars.insert(c);
        }

        int diff = 0;
        for (auto &c : chars) {
            diff += abs(freq_t[c] - freq_s[c]);
        }
        return diff / 2;
    }
};

int main()
{
    Solution solver;
    string s1 = "bab";
    string t1 = "aba";
    string s2 = "leetcode";
    string t2 = "practice";
    string s3 = "anagram";
    string t3 = "mangaar";
    cout << solver.minSteps(s1, t1) << endl;
    cout << solver.minSteps(s2, t2) << endl;
    cout << solver.minSteps(s3, t3) << endl;
}
