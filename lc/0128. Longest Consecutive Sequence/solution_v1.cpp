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
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int ret = 0;
        for (auto x : nums) {
            if (set.find(x - 1) == set.end()) {
                int l = 0;
                while (set.find(x) != set.end()) {
                    l++;
                    x++;
                }
                ret = max(ret, l);
            }
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {100, 4, 200, 1, 3, 2};
    vector<int> v2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << solver.longestConsecutive(v1) << endl;
    cout << solver.longestConsecutive(v2) << endl;
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
