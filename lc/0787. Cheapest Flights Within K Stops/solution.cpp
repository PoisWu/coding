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
        vector<int> dist(n, 1000000);
        dist[src] = 0;
        vector<vector<int>> dist_matrix(n, vector<int>(n, 1000000));
        for (int i = 0; i < n; i++) {
            dist_matrix[i][i] = 0;
        }
        for (auto flight : flights) {
            dist_matrix[flight[0]][flight[1]] = flight[2];
        }
        vector<bool> isDone(n, false);
        vector<int> pre(n, -1);

        for (int i = 0; i < n; i++) {
            // find the smallest, not done yet;
            int lowest_price = 1000000;
            int tmp = src;
            for (int j = 0; j < n; j++) {
                if (dist[j] < lowest_price && !isDone[j]) {
                    lowest_price = dist[j];
                    tmp = j;
                }
            }
            isDone[tmp] = true;
            for (int j = 0; j < n; j++) {
                if (!isDone[j]) {
                    if (dist[tmp] + dist_matrix[tmp][j] < dist[j]) {
                        pre[j] =
                            min(tmp; dist[j] = dist[tmp] + dist_matrix[tmp][j]);
                    }
                }
            }
        }
        if (dist[dst] != 1000000) {
            return dist[dst];
        } else {
            return -1;
        }
        return 0;
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
    // cout << solver.findCheapestPrice(4,v1,0,3,1) << endl;
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
