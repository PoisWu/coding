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
private:
    Trie *next[26];
    bool isEnd;

public:
    Trie()
    {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        isEnd = false;
    };

    ~True()
    {
        for (int i = 0; i < 26; i++) {
            if (this->next[i] != NULL) {
                delete this->next[i];
            }
        }
    }

    void insert(string word)
    {
        Trie *t = this;
        for (char c : word) {
            if (t->next[c - 'a'] == NULL) {
                t->next[c - 'a'] = new Trie();
            }
            t = t->next[c - 'a'];
        }
        t->isEnd = true;
    };

    bool search(string word)
    {
        Trie *t = this;
        for (char c : word) {
            if (t->next[c - 'a'] == NULL) {
                return false;
            }
            t = t->next[c - 'a'];
        };
        return t->isEnd;
    };

    bool startsWith(string prefix)
    {
        Trie *t = this;
        for (char c : prefix) {
            if (t->next[c - 'a'] == NULL) {
                return false;
            }
            t = t->next[c - 'a'];
        };
        return true;
    };
};


int main()
{
    Trie mytrie = Trie();
    mytrie.insert("apple");
    cout << mytrie.search("apple") << endl;
    cout << mytrie.startsWith("app") << endl;
    cout << mytrie.search("app") << endl;
    mytrie.insert("app");
    cout << mytrie.search("app") << endl;
    string s1 = "";
    string t1 = "";
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
