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
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<pair<int, int>> p;
        for (auto I : intervals) {
            p.emplace_back(I[0], 1);
            p.emplace_back(I[1], -1);
        }
        p.emplace_back(newInterval[0], 1);
        p.emplace_back(newInterval[1], -1);
        sort(p.begin(), p.end(), cmp);

        int sum = 0;
        vector<vector<int>> ret;
        int start;
        int end;
        for (int i = 0; i < p.size(); i++) {
            if (sum == 0) {
                start = p[i].first;
            } else if (sum > 0 && sum + p[i].second == 0) {
                end = p[i].first;
                ret.push_back({start, end});
            }
            sum += p[i].second;
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
