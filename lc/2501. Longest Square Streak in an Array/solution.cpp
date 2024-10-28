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
    int longestSquareStreak(vector<int> &nums)
    {
        map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        int ret = -1;

        for (auto it : freq) {
            int cnt = 1;
            int val = it.first;
            while (val < 46340 && freq.find(val * val) != freq.end() &&
                   freq[val * val] != 0) {
                cnt++;
                val = val * val;
                freq[val] = 0;
            }
            if (cnt > 1) {
                ret = max(ret, cnt);
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {4, 3, 6, 16, 8, 2};
    cout << solver.longestSquareStreak(v1) << endl;
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
