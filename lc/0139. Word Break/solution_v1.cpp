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
public:
    class Trie
    {
    public:
        bool isEnd;
        Trie *next[26];
        Trie()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    int memo[301];
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // build the trie
        Trie *root = new Trie();
        for (string word : wordDict) {
            Trie *trie = root;
            for (char c : word) {
                if (trie->next[c - 'a'] == NULL) {
                    trie->next[c - 'a'] = new Trie();
                }
                trie = trie->next[c - 'a'];
            }
            trie->isEnd = true;
        }
        for (int i = 0; i < s.length(); i++) {
            memo[i] = 0;
        }
        // try break s
        return dfs(s, 0, root);
    }
    bool dfs(string s, int cur, Trie *root)
    {
        if (cur == s.length()) {
            return true;
        }
        if (memo[cur] == 1) {
            return false;
        }
        bool ret = false;
        Trie *trie = root;
        for (int i = cur; i < s.length(); i++) {
            char c = s[i];
            if (trie->next[c - 'a'] == NULL) {
                break;
            }
            trie = trie->next[c - 'a'];
            if (trie->isEnd) {
                ret = ret | dfs(s, i + 1, root);
            }
        }
        memo[cur] = 1;
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.<< endl;
    print_vector(solver.);
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
