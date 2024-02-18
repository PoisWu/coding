#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // build a list of pair
        // (difference in heights, how far it can go after crossing the )
        vector<pair<int, int>> h_idx;
        int diff_height = 0;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[i - 1]) {
                h_idx.emplace_back(diff_height, i - 1);
                diff_height = heights[i] - heights[i - 1];
            }
        }
        h_idx.emplace_back(diff_height, heights.size() - 1);
        // for (int i = 0; i< h_idx.size() ; i++){
        //     cout << h_idx[i].first << " " << h_idx[i].second << endl;
        // }
        // bricks : remain bricks
        // ladders : remain ladders
        multiset<int> pre_height;
        int res = 0;
        for (int i = 0; i < h_idx.size(); i++) {
            if (bricks >= h_idx[i].first) {
                bricks = bricks - h_idx[i].first;
                res = h_idx[i].second;
                pre_height.insert(h_idx[i].first);
            } else {
                if (ladders > 0) {
                    int biggest_difference = *pre_height.rbegin();
                    if (biggest_difference > h_idx[i].first) {
                        bricks += biggest_difference;
                        bricks -= h_idx[i].first;
                        ladders--;
                        auto it = pre_height.find(biggest_difference);
                        pre_height.erase(it);
                        pre_height.insert(h_idx[i].first);
                    } else {
                        ladders--;
                    }
                    res = h_idx[i].second;
                } else {
                    break;
                }
            }
            while (pre_height.size() > ladders) {
                int small_difference = *pre_height.begin();
                auto it = pre_height.find(small_difference);
                pre_height.erase(it);
            }
        }
        return res;

        cout << "---------" << endl;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {4, 2, 7, 6, 9, 14, 12};
    vector<int> v2 = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    vector<int> v3 = {14, 3, 19, 3};
    cout << solver.furthestBuilding(v1, 5, 1) << endl;
    cout << solver.furthestBuilding(v2, 10, 2) << endl;
    cout << solver.furthestBuilding(v3, 17, 0) << endl;

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
