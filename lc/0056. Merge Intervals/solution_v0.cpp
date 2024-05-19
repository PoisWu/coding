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
private:
    static const int mod = 1000000007;

    static bool cmp(vector<int> first, vector<int> second)
    {
        return first[0] < second[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //[a1, b1] , [a2, b2] overlap if
        // suppose a1 <= a2
        // a1 <= a2 <= b1<= b2
        // Interval sorted,
        // I1
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        while (i < n) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            while (i < n && intervals[i][0] <= b) {
                b = max(b, intervals[i][1]);
                i++;
            }
            res.push_back({a, b});
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 3});
    v1.push_back({2, 6});
    v1.push_back({8, 10});
    v1.push_back({15, 18});
    print_2d_vector(solver.merge(v1));
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
