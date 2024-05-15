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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> q;
        for (int x : nums) {
            auto pos = lower_bound(q.begin(), q.end(), x);
            if (pos == q.end()) {
                q.push_back(x);
            } else {
                *pos = x;
            }
        }
        return q.size();
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {7, 7, 7, 7, 7, 7, 7};
    vector<int> v2 = {0, 1, 0, 3, 2, 3};
    vector<int> v3 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solver.lengthOfLIS(v1) << endl;
    cout << solver.lengthOfLIS(v2) << endl;
    cout << solver.lengthOfLIS(v3) << endl;
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
