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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int pathsum[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    pathsum[i][j] = matrix[i][j];
                } else {
                    if (j == 0) {
                        pathsum[i][j] =
                            min(pathsum[i - 1][j], pathsum[i - 1][j + 1]) +
                            matrix[i][j];
                    } else if (j == n - 1) {
                        pathsum[i][j] =
                            min(pathsum[i - 1][j], pathsum[i - 1][j - 1]) +
                            matrix[i][j];
                    } else {
                        pathsum[i][j] =
                            min(min(pathsum[i - 1][j - 1], pathsum[i - 1][j]),
                                pathsum[i - 1][j + 1]) +
                            matrix[i][j];
                    }
                }
            }
        }
        int minpath = pathsum[n - 1][0];
        for (int j = 0; j < n; j++) {
            if (pathsum[n - 1][j] < minpath)
                minpath = pathsum[n - 1][j];
        }
        return minpath;
    }
};
