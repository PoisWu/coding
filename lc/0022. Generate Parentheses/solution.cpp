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

public:
    vector<string> generateParenthesis(int n)
    {
        ret.clear();
        string w = "";
        dfs(w, n, 0);
        return ret;
    }
    void dfs(string &w, int nb_not_put, int nb_unpair)
    {
        if (nb_unpair == 0 && nb_not_put == 0) {
            ret.push_back(w);
        }

        if (nb_not_put != 0) {
            w.push_back('(');
            dfs(w, nb_not_put - 1, nb_unpair + 1);
            w.pop_back();
        }
        if (nb_unpair != 0) {
            w.push_back(')');
            dfs(w, nb_not_put, nb_unpair - 1);
            w.pop_back();
        }
    }
};


int main()
{
    Solution solver;
    print_vector(solver.generateParenthesis(3));
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
