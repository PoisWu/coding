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

    bool isPalindrome(string &word)
    {
        for (int i = 0, j = word.length() - 1; i <= j; i++, j--) {
            if (word[i] != word[j]) {
                return false;
            }
        }
        return true;
    }

public:
    string firstPalindrome(vector<string> &words)
    {
        for (string s : words) {
            if (isPalindrome(s)) {
                return s;
            }
        }
        return "";
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"abc", "car", "ada", "racecar", "cool"};
    cout << solver.firstPalindrome(v1) << endl;
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
