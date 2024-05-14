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
    vector<string> ret;
    vector<string> l = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0) {
            return {};
        }
        ret.clear();
        string w = "";
        dfs(digits, 0, w);
        return ret;
    }
    void dfs(string digits, int pos, string &w)
    {
        if (pos == digits.length()) {
            ret.push_back(w);
            return;
        }
        for (char c : l[digits[pos] - '0']) {
            w.push_back(c);
            dfs(digits, pos + 1, w);
            w.pop_back();
        }
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    print_vector(solver.letterCombinations("23"));
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
