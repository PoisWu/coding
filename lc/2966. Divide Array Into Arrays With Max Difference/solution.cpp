#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
    vector<vector<int>> divideArray(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() / 3; i++) {
            if (arr[3 * i + 2] - arr[3 * i] > k) {
                return {};
            } else {
                res.push_back({arr[3 * i], arr[3 * i + 1], arr[3 * i + 2]});
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    vector<int> v2 = {15, 13, 12, 13, 12, 14, 12, 2,  3, 13, 12,
                      14, 14, 13, 5,  12, 12, 2,  13, 2, 2};
    print_2d_vector(solver.divideArray(v2, 2));
}
