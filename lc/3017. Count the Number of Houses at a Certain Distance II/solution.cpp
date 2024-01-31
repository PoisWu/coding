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
        if (x > y) {
            y = x ^ y;
            x = x ^ y;
            y = x ^ y;
        }
        vector<long long> res(n, 0);

        // Compute in the circle
        int dxy = y - x;
        for (int i = 0; i < dxy / 2; i++) {
            res[i] += (dxy + 1) * 2
        }
        if (dxy % 2) {
            // dxy is odd
            res[dxy / 2 + 1] += dxy + 1
        }
        // Compute L
        int dlx = x;
        for (int i = 0; i < dlx; i++) {
            res[i] += (dlx - 1 - i) * 2
        }

        // Compute R
        int dyr = n - y - 1;
        for (int i = 0; i < dyr; i++) {
            res[i] += (dyr - 1 - i) * 2;
        }

        // compute L/R
        if (dxy) {
            // x != y
            for (int i = 3; 1 + dlx + dyr; i++) {
                res[i] += min(i - 2, 1 + dlx + dyr - i + 1);
            }
        } else {
            for (int i = 2; dlx + dyr; i++) {
                res[i] += min(i - 1, dlx + dyr - i + 1);
            }
        }
        // compute L/C
    }
};
