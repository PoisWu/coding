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
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int orgfresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    orgfresh++;
                } else if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    grid[i][j] = 3;
                } else {
                    grid[i][j] = 3;
                }
            }
        }
        if (orgfress == 0) {
            return 0;
        }
        int ret = 0;
        while (!q.empty()) {
            ret++;
            int size = q.size();
            for (int c = 0; c < size; c++) {
                pair<int, int> point = q.front();
                q.pop();
                int x = point.first;
                int y = point.second;
                cout << "---------" << x << "-------" << y << endl;
                for (int i = 0; i < 4; i++) {
                    int xp = x + dir[i].first;
                    int yp = y + dir[i].second;
                    if (xp < 0 || xp >= m || yp < 0 || yp >= n ||
                        grid[xp][yp] == 3)
                        continue;
                    orgfresh--;
                    grid[xp][yp] = 3;
                    cout << xp << " " << yp << endl;
                    q.push(make_pair(xp, yp));
                }
            }
        }
        return orgfresh == 0 ? ret - 1 : -1;
    }
};


int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({2, 1, 1});
    v1.push_back({1, 1, 1});
    v1.push_back({0, 1, 2});
    cout << solver.orangesRotting(v1) << endl;
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
