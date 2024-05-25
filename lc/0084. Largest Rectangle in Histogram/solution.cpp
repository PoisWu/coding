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
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();
        vector<int> nextsmall(n, n);
        vector<int> prevsmall(n, -1);
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                nextsmall[s.top()] = i;
                s.pop();
            }
            if (!s.empty())
                prevsmall[i] = s.top();
            s.push(i);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, heights[i] * (nextsmall[i] - prevsmall[i] - 1));
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {2, 1, 5, 6, 2, 3};
    string s1 = "";
    string t1 = "";
    cout << solver.largestRectangleArea(v1) << endl;
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
