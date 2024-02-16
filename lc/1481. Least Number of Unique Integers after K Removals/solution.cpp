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
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        vector<pair<int, int>> freq_pair;
        for (auto it : freq) {
            freq_pair.emplace_back(it.first, it.second);
        }
        sort(freq_pair.begin(), freq_pair.end(),
             [](const pair<int, int> &left, const pair<int, int> &right) {
                 return left.second < right.second;
             });
        int res = freq_pair.size();
        for (int i = 0; i < freq_pair.size(); i++) {
            int ifreq = freq_pair[i].second;

            if (k >= ifreq) {
                k -= ifreq;
                res--;
            } else {
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {5, 5, 4};
    vector<int> v2 = {4, 3, 1, 1, 3, 3, 2};
    cout << solver.findLeastNumOfUniqueInts(v1, 1) << endl;
    cout << solver.findLeastNumOfUniqueInts(v2, 3) << endl;
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
