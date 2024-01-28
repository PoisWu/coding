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
    static const int mod = 1000000007;

public:
    int maximumLength(vector<int> &nums)
    {
        map<long long, int> freq;
        for (auto &x : nums) {
            freq[(long long) x]++;
        }
        int res = 1;

        for (auto &elem : freq) {
            int temp = 0;
            if (elem.first == 1) {
                res = max(res, freq[1] - (freq[1] % 2 ? 0 : 1));
                freq[1] = 0;
                continue;
            }
            long long int val = elem.first;

            while (freq[val] >= 2) {
                temp += 2;
                freq[val] = 0;
                val = val * val;
            }
            if (freq[val]) {
                temp++;
            } else {
                temp--;
            }

            res = max(res, temp);
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {5, 4, 1, 2, 2};
    vector<int> v2 = {14, 14, 196, 196, 38416, 38416};
    cout << solver.maximumLength(v1) << endl;
    cout << solver.maximumLength(v2) << endl;

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
