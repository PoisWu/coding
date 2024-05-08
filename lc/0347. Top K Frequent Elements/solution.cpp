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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int x : nums) {
            map[x]++;  // val, freq
        }
        vector<pair<int, int>> q;

        for (auto ele : map) {
            q.emplace_back(ele.second, ele.first);
        }
        sort(q.begin(), q.end());
        int n = q.size();
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(q[n - 1 - i].second);
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 1, 1, 2, 2, 3};
    print_vector(solver.topKFrequent(v1, 2));
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
