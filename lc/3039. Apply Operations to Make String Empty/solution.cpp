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
    static const int mod = 1000000007;

public:
    string lastNonEmptyString(string s)
    {
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
        }
        int max_freq = -1;
        unordered_set<char> al;
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                if (max_freq < arr[i]) {
                    max_freq = arr[i];
                    al.clear();
                    al.insert(i + 'a');
                } else if (max_freq == arr[i]) {
                    al.insert(i + 'a');
                }
            }
        }
        string res = "";
        int i = s.length() - 1;
        while (!al.empty()) {
            if (al.find(s[i]) != al.end()) {
                res = s[i] + res;
                al.erase(s[i]);
            }
            i--;
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "aabcbbca";
    string t1 = "abcd";
    cout << solver.lastNonEmptyString(s1) << endl;
    cout << solver.lastNonEmptyString(t1) << endl;
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
