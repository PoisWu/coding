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
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> fifo;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    fifo.push(make_pair(i, j));
                    cnt++;
                }
                while (!fifo.empty()) {
                    pair<int, int> point = fifo.front();
                    fifo.pop();
                    int x = point.first, y = point.second;
                    grid[x][y] = '0';
                    if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        fifo.push(make_pair(x - 1, y));
                    if (x + 1 < m && grid[x + 1][y] == '1')
                        fifo.push(make_pair(x + 1, y));
                    if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        fifo.push(make_pair(x, y - 1));
                    if (y + 1 < n && grid[x][y + 1] == '1')
                        fifo.push(make_pair(x, y + 1));
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solver;
    vector<vector<char>> v1 = {};
    v1.push_back({'1', '1', '1', '1', '0'});
    v1.push_back({'1', '1', '0', '1', '0'});
    v1.push_back({'1', '1', '0', '0', '0'});
    v1.push_back({'0', '0', '0', '0', '0'});

    vector<vector<char>> v2 = {};

    v2.push_back({'1', '1', '0', '0', '0'});
    v2.push_back({'1', '1', '0', '0', '0'});
    v2.push_back({'0', '0', '1', '0', '0'});
    v2.push_back({'0', '0', '0', '1', '1'});

    cout << solver.numIsLands(v1) << endl;
    cout << solver.numIsLands(v2) << endl;
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
