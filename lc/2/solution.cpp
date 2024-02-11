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
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &patterns)
    {
        int n = nums.size();
        int m = patterns.size();
        int ans = 0;
        for (int i = 0; i < n - m; i++) {
            bool isvalid = true;
            for (int k = 0; k < m && isvalid; k++) {
                switch (patterns[k]) {
                case 1:
                    if (nums[i + k + 1] <= nums[i + k]) {
                        isvalid = false;
                    }
                    break;
                case 0:
                    if (nums[i + k + 1] != nums[i + k]) {
                        isvalid = false;
                    }
                    break;
                case -1:
                    if (nums[i + k + 1] >= nums[i + k]) {
                        isvalid = false;
                    }
                    break;
                }
            }
            if (isvalid) {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {1, 1};

    cout << solver.countMatchingSubarrays(v1, v2) << endl;
    return 0;

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

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

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
