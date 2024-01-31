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
void print_2d_vector(vector<vector<T>> vvec)
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
    static const int mod = 1000000007;

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix_sum(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum = sum + matrix[i][j];
                prefix_sum[i][j] = sum;
            }
        }
        int res = 0;
        for (int w = 1; w <= m; w++) {
            // build table for width w (row) eg [i][0]....[i][w-1];
            vector<vector<int>> vpre_sum(n, vector<int>(m - w + 1, 0));
            // dim(vpre_sum) = n * (m-w+1);
            // vpre_sum[i][j] = sum of ith first row with w windows, start at
            // [.][j];
            for (int j = w - 1; j < m; j++) {
                int sum = 0;
                // sum over vertital
                for (int i = 0; i < n; i++) {
                    sum += prefix_sum[i][j];
                    // for ith row
                    // sum = prefix_sum[i][j] - pref_sum[i][j-w] execpt for the
                    // j = w-1;
                    if (j - w >= 0) {
                        sum -= prefix_sum[i][j - w];
                    }
                    vpre_sum[i][j - w + 1] = sum;
                }
            }
            for (int j = 0; j < m - w + 1; j++) {
                //
                for (int i = n - 1; i >= 0; i--) {
                    if (vpre_sum[i][j] == target) {
                        res++;
                    }
                    for (int smalli = 0; smalli < i; smalli++) {
                        if (vpre_sum[i][j] - vpre_sum[smalli][j] == target) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({0, 0, 1, 0, 0});
    v1.push_back({1, 0, 1, 1, 0});
    v1.push_back({0, 0, 1, 1, 1});
    v1.push_back({0, 1, 1, 0, 1});
    v1.push_back({0, 0, 0, 1, 0});
    v1.push_back({0, 1, 1, 0, 1});
    v1.push_back({0, 0, 1, 1, 1});
    cout << solver.numSubmatrixSumTarget(v1, 0) << endl;
    string s1 = "";
    string t1 = "";

    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    // TreeNode two = TreeNode(2);
    // TreeNode nine = TreeNode(9);
    // TreeNode four = TreeNode(4, &nine, &two);
    // TreeNode five = TreeNode(5, NULL, &four);
    // TreeNode ten = TreeNode(10);
    // TreeNode six = TreeNode(6);
    // TreeNode three = TreeNode(3, &ten, &six);
    // TreeNode one = TreeNode(1, &five, &three);
}
