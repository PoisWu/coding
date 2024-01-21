#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};


using namespace std;

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

class Solution
{
public:
    vector<long long> countOfPairs(int n, int x, int y)
    {
        x = x - 1;
        y = y - 1;
        vector<vector<long long>> dist(n, vector<long long>(n, 1000000 * n));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dist[j][i] = j - i;
                dist[i][j] = j - i;
            }
        }

        if (x > y) {
            y = x ^ y;
            x = x ^ y;
            y = x ^ y;
        }
        dist[x][y] = 1;
        dist[y][x] = 1;
        print_2d_vector(dist);
        if (y - x) {
            for (int k = y + x / 2; k < n; k++) {
                if (dist[x][k] > dist[x][y] + dist[y][k]) {
                    dist[x][k] = dist[x][y] + dist[y][k];
                    dist[k][x] = dist[k][y] + dist[y][x];
                }
            }
            for (int k = y + x / 2; k >= 0; k--) {
                if (dist[y][k] > dist[y][x] + dist[x][k]) {
                    dist[y][k] = dist[x][y] + dist[x][k];
                    dist[k][y] = dist[k][y] + dist[x][x];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][x] + dist[x][j]) {
                        dist[i][j] = dist[i][x] + dist[x][j];
                    }
                    if (dist[i][j] > dist[i][y] + dist[y][j]) {
                        dist[i][j] = dist[i][y] + dist[y][j];
                    }
                }
            }
        }

        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[dist[i][j] - 1] += 2;
            }
        }
        return res;
    }
};
