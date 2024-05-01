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

class WordDictionary
{
private:
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
    TrieNode *root;

    bool dfs(TrieNode *node, string s, int idx)
    {
        if (node == NULL)
            return false;
        int n = s.length();
        if (idx == n)
            return node->isEnd;
        char c = s[idx];

        if (c != '.') {
            return dfs(node->next[c - 'a'], s, idx + 1);
        }

        for (int i = 0; i < 26; i++) {
            if (dfs(node->next[i], s, idx + 1))
                return true;
        }
        return false;
    }

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word)
    {
        TrieNode *node = this->root;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) { return dfs(root, word, 0); }
};


int main()
{
    WordDictionary dict = WordDictionary();
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("pad") << endl;
    cout << dict.search("..d") << endl;
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
