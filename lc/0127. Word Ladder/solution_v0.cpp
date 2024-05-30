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
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        word_set.insert(beginWord);
        unordered_map<string, vector<string>> graph;

        for (string s : word_set) {
            for (int i = 0; i < s.length(); i++) {
                string t = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == s[i])
                        continue;
                    t[i] = c;
                    if (word_set.find(t) != word_set.end()) {
                        graph[s].push_back(t);
                    }
                }
            }
        }

        // bfs
        queue<string> q;
        q.push(beginWord);
        word_set.erase(beginWord);
        int round = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();
                if (s == endWord) {
                    return round;
                }
                for (string neighbor : graph[s]) {
                    if (word_set.find(neighbor) != word_set.end()) {
                        q.push(neighbor);
                        word_set.erase(neighbor);
                    }
                }
            }
            round++;
        }
        return 0;
    }
};


int main()
{
    Solution solver;
    vector<string> v1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    string s1 = "";
    string t1 = "";
    cout << solver.ladderLength("hit", "cog", v1) << endl;
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
