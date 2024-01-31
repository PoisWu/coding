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



int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n;
        scanf("%d %d\n", &n);
        int a[n];
        int b[n];
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", a + i);
        }
        scanf("%d\n", a + n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", b + i);
        }
        scanf("%d\n", b + n);
    }
}
