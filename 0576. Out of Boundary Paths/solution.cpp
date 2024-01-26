#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
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
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


class Solution
{
private:
    static const int modulo = 1000000007;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int res = 0;
        // There are ball[i][j] different path to arrive at (i,j)
        int ball[2][m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ball[0][i][j] = 0;
            }
        }
        ball[0][startRow][startColumn] = 1;
        for (int it = 0; it < maxMove; it++) {
            // update from ball[it%2] to ball[(it+1)%2]
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ball[(it + 1) % 2][i][j] = 0;
                    // case i left
                    if (i - 1 > -1) {
                        ball[(it + 1) % 2][i][j] = (ball[(it + 1) % 2][i][j] +
                                                    ball[it % 2][i - 1][j]) %
                                                   modulo;
                    } else {
                        // i = 0;
                        res = (res + ball[it % 2][0][j]) % modulo;
                    }

                    // case i right
                    if (i + 1 < m) {
                        ball[(it + 1) % 2][i][j] = (ball[(it + 1) % 2][i][j] +
                                                    ball[it % 2][i + 1][j]) %
                                                   modulo;
                    } else {
                        // i = m - 1
                        res = (res + ball[it % 2][m - 1][j]) % modulo;
                    }

                    // case j up
                    if (j - 1 > -1) {
                        ball[(it + 1) % 2][i][j] = (ball[(it + 1) % 2][i][j] +
                                                    ball[it % 2][i][j - 1]) %
                                                   modulo;
                    } else {
                        // j = 0
                        res = (res + ball[it % 2][i][0]) % modulo;
                    }

                    // case j down
                    if (j + 1 < n) {
                        ball[(it + 1) % 2][i][j] = (ball[(it + 1) % 2][i][j] +
                                                    ball[it % 2][i][j + 1]) %
                                                   modulo;
                    } else {
                        // j = n-1
                        res = (res + ball[it % 2][i][n - 1]) % modulo;
                    }
                    // cout << ball[it  % 2][i][j] << " " ;
                }
                // cout << endl;
            }
            // cout << "=====" << endl;
        }
        return res;
    }
};

int main()
{
    Solution solver;
    cout << solver.findPath(2, 2, 2, 0, 0) << endl;
    cout << solver.findPath(1, 3, 3, 0, 1) << endl;
}
