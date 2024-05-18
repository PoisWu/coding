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
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> rightmost(n, 0);
        vector<int> leftmost(n, 0);  // i
        for (int i = 1; i < n; i++) {
            leftmost[i] = max(leftmost[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightmost[i] = max(rightmost[i + 1], height[i + 1]);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += max(0, min(leftmost[i], rightmost[i]) - height[i]);
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    string s1 = "";
    string t1 = "";
    cout << solver.trap(v1) << endl;
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
