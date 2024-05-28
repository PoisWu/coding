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
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first < b.first;
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> v;
        for (auto I : intervals) {
            v.emplace_back(I[0], I[1]);
        }
        vector<vector<int>> ret;

        sort(v.begin(), v.end(), cmp);
        int i = 0;
        int n = intervals.size();
        while (i < n) {
            int start = v[i].first;
            int end = v[i].second;
            while (i < n && v[i].first <= end) {
                end = max(end, v[i].second);
                i++;
            }
            ret.push_back({start, end});
        }
        return ret;
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
