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
    int waysToReachStair(int k)
    {
        int ret = 0;
        vector<pair<int, int>> map;
        int pos = 1;
        if (pos - k >= 0) {
            map.emplace_back(0, pos - k);
        }
        int jump = 1;
        for (int i = 0; i < 30; i++) {
            pos += jump;
            if (pos - k >= 0) {
                map.emplace_back(i + 1, pos - k);
            }
            if (i != 30)
                jump = jump * 2;
        }
        for (auto m : map) {
            int nb_jump = m.first;
            int nb_dec = m.second;
            if (nb_dec > nb_jump + 1) {
                continue;
            }
            ret += c(nb_jump + 1, nb_dec);
        }
        return ret;
    }
    long long c(long long n, long long k)
    {
        long long a = 1;
        k = min(n - k, k);
        for (int i = 0; i < k; i++) {
            a = a * (n - i) / (i + 1);
        }
        return a;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.waysToReachStair(8388603) << endl;
    cout << solver.waysToReachStair(1) << endl;
    cout << solver.waysToReachStair(0) << endl;
    cout << solver.waysToReachStair(2) << endl;
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
