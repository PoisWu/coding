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
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

    class Trie
    {
    public:
        Trie *next[26];
        bool isEnd;
        int count;
        Trie()
        {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            isEnd = false;
            count = 0;
        }
    };
    unordered_set<string> rets;
    int m;
    int n;
    int isvisited[12][12];
    Trie *root;

    void dfs(vector<vector<char>> &board, int i, int j, string &w, Trie *node)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || isvisited[i][j] == 1) {
            return;
        }
        char c = board[i][j];
        if (node->next[c - 'a'] == NULL)
            return;
        if (node->count == 0)
            return;

        isvisited[i][j] = 1;
        w.push_back(c);
        node = node->next[c - 'a'];
        if (node->isEnd) {
            rets.insert(w);
            node->isEnd = false;
            rmword(w);
        }
        dfs(board, i + 1, j, w, node);
        dfs(board, i - 1, j, w, node);
        dfs(board, i, j + 1, w, node);
        dfs(board, i, j - 1, w, node);
        isvisited[i][j] = 0;
        w.pop_back();
    }

    void rmword(string w)
    {
        Trie *node = root;
        for (char c : w) {
            node->count--;
            node = node->next[c - 'a'];
        }
        node->count--;
    }


public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = new Trie();

        for (string word : words) {
            Trie *node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == NULL) {
                    node->next[c - 'a'] = new Trie();
                }
                node->count++;
                node = node->next[c - 'a'];
            }
            node->isEnd = true;
            node->count++;
        }
        rets.clear();
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                isvisited[i][j] = 0;
            }
        }

        m = board.size();
        n = board[0].size();
        string w = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, w, root);
            }
        }
        return vector<string>(rets.begin(), rets.end());
    }
};

int main()
{
    Solution solver;
    vector<vector<char>> v1 = {};
    v1.push_back({'o', 'a', 'a', 'n'});
    v1.push_back({'e', 't', 'a', 'e'});
    v1.push_back({'i', 'h', 'k', 'r'});
    v1.push_back({'i', 'f', 'l', 'v'});
    // vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> words = {"oa", "oaa"};
    print_vector(solver.findWords(v1, words));
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
