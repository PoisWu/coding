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
private:
    static const int mod = 1000000007;

public:
    bool isValid(string s)
    {
        vector<char> stack;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
            } else {
                if (s[i] == ')' && stack.back() != '(')
                    return false;
                if (s[i] == '}' && stack.back() != '{')
                    return false;
                if (s[i] == ']' && stack.back() != '[')
                    return false;
                stack.pop_back();
            }
        }
        return true;
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
