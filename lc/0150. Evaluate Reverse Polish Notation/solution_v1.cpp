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
    int evalRPN(vector<string> &tokens)
    {
        stack<int> q;
        for (auto s : tokens) {
            if (s == "+") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a + b);
            } else if (s == "*") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a * b);
            } else if (s == "-") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a - b);
            } else if (s == "/") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a / b);
            } else {
                q.push(stoi(s));
            }
        }
        return q.top();
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
