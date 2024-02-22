#include <algorithm>
#include <array>
#include <bitset>
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
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int trustout[1001] = {0};
        int trustin[1001] = {0};
        for (int i = 0; i < trust.size(); i++) {
            trustout[trust[i][0]]++;
            trustin[trust[i][1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (trustin[i] == n - 1 && trustout[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 2});
    vector<vector<int>> v2 = {};
    v2.push_back({1, 3});
    v2.push_back({2, 3});
    cout << solver.findJudge(2, v1) << endl;
    cout << solver.findJudge(3, v2) << endl;
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
