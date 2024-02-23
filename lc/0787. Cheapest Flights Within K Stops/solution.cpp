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
    int findCheapestPrice(int n,
                          vector<vector<int>> &flights,
                          int src,
                          int dst,
                          int k)
    {
        vector<vector<int>> dp(k + 2, vector<int>(n, 100 * 10000));
        dp[0][src] = 0;

        vector<vector<int>> price_table(n, vector<int>(n, 100 * 10000));
        for (auto flight : flights) {
            price_table[flight[0]][flight[1]] = flight[2];
        }

        for (int round = 1; round <= k + 1; round++) {
            for (int city = 0; city < n; city++) {
                for (int from_city = 0; from_city < n; from_city++) {
                    dp[round][city] =
                        min(dp[round][city], dp[round - 1][from_city] +
                                                 price_table[from_city][city]);
                }
            }
        }
        int res = 100 * 10000;
        for (int round = 0; round < k + 2; round++) {
            res = min(dp[round][dst], res);
        }
        if (res == 100 * 10000) {
            return -1;
        } else {
            return res;
        }
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({0, 1, 100});
    v1.push_back({1, 2, 100});
    v1.push_back({2, 0, 100});
    v1.push_back({1, 3, 600});
    v1.push_back({2, 3, 200});
    vector<vector<int>> v2 = {};
    v2.push_back({0, 1, 1});
    v2.push_back({0, 2, 5});
    v2.push_back({1, 2, 1});
    v2.push_back({2, 3, 1});
    cout << solver.findCheapestPrice(4, v1, 0, 3, 1) << endl;
    cout << solver.findCheapestPrice(4, v2, 0, 3, 1) << endl;
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
