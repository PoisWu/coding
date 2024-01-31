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

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        x = x - 1;
        y = y - 1;
        vector<vector<int>> dist(n, vector<int>(n, 1000 * n));
        for (int i = 0; i < n - 1; i++) {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }
        dist[x][y] = 1;
        dist[y][x] = 1;

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[dist[i][j] - 1] += 2;
            }
        }
        return res;
    }
};
