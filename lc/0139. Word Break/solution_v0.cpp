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
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool isEnd;
        TrieNode()
        {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            isEnd = false;
        }
    };
    int memo[301];


public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // building trie for wordDict
        TrieNode *root = new TrieNode();
        for (string s : wordDict) {
            TrieNode *node = root;
            for (char ch : s) {
                if (node->next[ch - 'a'] == NULL) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->isEnd = true;
        }
        return dfs(s, 0, root);
    }

    bool dfs(string &s, int cur, TrieNode *root)
    {
        // check wether there is a wordbreak from s[cur:...]
        if (cur >= s.length())
            return true;

        if (memo[cur] == 1)
            return false;


        TrieNode *node = root;
        for (int i = cur; i < s.length(); i++) {
            if (node->next[s[i] - 'a'] == NULL) {
                break;
            }
            node = node->next[s[i] - 'a'];
            if (node->isEnd && dfs(s, i + 1, root)) {
                return true;
            }
        }
        memo[cur] = 1;
        return false;
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"leet", "code"};
    string s1 = "leetcode";
    cout << solver.wordBreak(s1, v1) << endl;
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
