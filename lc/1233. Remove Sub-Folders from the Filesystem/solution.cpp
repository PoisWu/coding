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


class Trie
{
public:
    bool isEnd;
    unordered_map<string, Trie *> next;
    Trie()
    {
        isEnd = false;
        return;
    }
    void insert(string s)
    {
        int n = s.length();
        int start = 1;
        vector<string> path;
        while (start < n) {
            int end = start + 1;
            while (end < n && s[end] != '/') {
                end++;
            }
            path.push_back(s.substr(start, end - start));

            start = end + 1;
        }

        Trie *cur = this;
        for (string p : path) {
            if (cur->next.count(p) == 0) {
                cur->next[p] = new Trie();
            }
            cur = cur->next[p];
        }
        cur->isEnd = true;
    }
};


class Solution
{
public:
    string vtos(vector<string> path_block)
    {
        string s = "";
        for (string t : path_block) {
            s.push_back('/');
            s.append(t);
        }
        return s;
    }
    vector<string> result;

    void dfs(Trie *t, vector<string> &path_block)
    {
        if (t->isEnd) {
            result.push_back(vtos(path_block));
            return;
        } else {
            for (auto const &x : t->next) {
                path_block.push_back(x.first);

                dfs(x.second, path_block);
                path_block.pop_back();
            }
        }
    };


    vector<string> removeSubfolders(vector<string> &folder)
    {
        Trie *trie = new Trie();
        // building trie;
        for (string s : folder) {
            trie->insert(s);
        }
        result.clear();
        vector<string> path_block = vector<string>();
        dfs(trie, path_block);
        return result;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    vector<string> s1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> s2 = {"/a/b/c", "/a/b/ca", "/a/b/d"};

    print_vector(solver.removeSubfolders(s2));
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
