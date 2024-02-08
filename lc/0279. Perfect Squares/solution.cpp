#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
    int aux(int n, int *nb)
    {
        if (nb[n] != 0) {
            return nb[n];
        }
        int i = 1;
        int minnum = INT_MAX;
        while (i * i <= n) {
            int tmp = (n - i * i) ? 1 + aux(n - i * i, nb) : 1;
            if (tmp < minnum) {
                minnum = tmp;
            }
            i++;
        }
        nb[n] = minnum;
        return nb[n];
    }

public:
    int numSquares(int n)
    {
        int nb[10002] = {0};
        for (int i = 1; i * i <= n; i++) {
            nb[i * i] = 1;
        }
        // cout << nb[4] << endl;
        return aux(n, nb);
    }
};

int main()
{
    Solution solver;
    cout << solver.numSquares(12) << endl;
    cout << solver.numSquares(13) << endl;
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
