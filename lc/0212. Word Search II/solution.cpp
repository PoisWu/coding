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
        Trie()
        {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            isEnd = false;
        }
    };
    vector<string> rets;
    int m;
    int n;

    void dfs(vector<vector<char>> &board, int x, int y, string w, Trie *node)
    {
        char c = board[x][y];
        if (node->next[c - 'a'] == NULL) {
            return;
        }
        node = node->next[c - 'a'];
        w += c;

        if (node->isEnd) {
            rets.push_back(w);
        }

        if (x - 1 >= 0) {
            dfs(board, x - 1, y, w, node);
        }
        if (x + 1 < m) {
            dfs(board, x + 1, y, w, node);
        }
        if (y - 1 >= 0) {
            dfs(board, x, y - 1, w, node);
        }
        if (y + 1 < n) {
            dfs(board, x, y + 1, w, node);
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = new Trie();

        for (string word : words) {
            Trie *node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == NULL) {
                    node->next[c - 'a'] = new Trie();
                }
            }
            node->isEnd = true;
        }
        rets.resize(0);
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, "", root);
            }
        }
        return rets;
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
    vector<string> words = {"oath", "pea", "eat", "rain"};
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
