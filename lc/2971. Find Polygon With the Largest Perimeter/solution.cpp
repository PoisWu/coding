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
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long tmp = 0;
        vector<long long> presum;
        for (int x : nums) {
            tmp += x;
            presum.push_back(tmp);
        }

        long long res = -1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] < presum[i - 1]) {
                res = max(res, presum[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {5, 5, 5};
    vector<int> v2 = {1, 12, 1, 2, 5, 50, 3};
    vector<int> v3 = {5, 5, 50};
    cout << solver.largestPerimeter(v1) << endl;
    cout << solver.largestPerimeter(v2) << endl;
    cout << solver.largestPerimeter(v3) << endl;
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
