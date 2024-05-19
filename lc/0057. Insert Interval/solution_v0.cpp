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

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> rets;

        bool flag = true;
        int n = intervals.size();
        int i = 0;

        while (i < n) {
            int start;
            int end;
            if (flag && newInterval[0] <= intervals[i][0]) {
                flag = false;
                start = newInterval[0];
                end = newInterval[1];
                while (i < n && intervals[i][0] <= end) {
                    end = max(end, intervals[i][1]);
                    i++;
                }
            } else {
                start = intervals[i][0];
                end = intervals[i][1];
                while (i < n && intervals[i][0] <= end) {
                    if (flag && newInterval[0] <= end) {
                        end = max(end, newInterval[1]);
                        flag = false;
                    }
                    end = max(end, intervals[i][1]);
                    i++;
                }
            }
            rets.push_back({start, end});
        }
        if (flag) {
            rets.push_back(newInterval);
        }
        return rets;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 3});
    v1.push_back({6, 9});
    vector<int> newI = {2, 5};
    print_2d_vector(solver.insert(v1, newI));
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
