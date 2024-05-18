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

    static bool cmp(pair<int, char> &a, pair<int, char> &b)
    {
        return a.first < b.first;
    }

public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        vector<pair<int, char>> q;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int l = min(abs(points[i][0]), abs(points[i][1]));
            q.push_back(make_pair(l, s[i]));
        }
        sort(q.begin(), q.end(), cmp);
        vector<int> freq(26, 0);
        int ret = 0;
        bool c = true;
        for (int i = 0; i < n && c;) {
            int tmp = q[i].first;
            int j = i;
            while (j < n && q[j].first == tmp) {
                if (freq[q[j].second]++ > 1) {
                    c = false;
                    ret = max(ret, tmp - 1);
                }
                j++;
            }
            ret = max(tmp, ret);
            i = j;
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v1 = {};
    v1.push_back({2, 2});
    v1.push_back({-1, -2});
    v1.push_back({-4, 4});
    v1.push_back({-3, 1});
    v1.push_back({3, -3});

    string s1 = "abdca";
    Solution solver;
    cout << solver.maxPointsInsideSquare(v1, s1);
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
