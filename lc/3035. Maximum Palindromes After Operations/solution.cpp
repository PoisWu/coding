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
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        vector<int> sizes;
        int nbodd = 0;
        int total = 0;
        for (auto w : words) {
            int len = w.length();
            total += len;
            sizes.push_back(len);
            for (int i = 0; i < len; i++) {
                nbodd ^= 1 << (w[i] - 'a');
            }
        }
        int nb_al_odd = __builtin_popcount(nbodd);
        int nb_even = total - nb_al_odd;
        sort(sizes.begin(), sizes.end());
        int ans = 0;
        for (int i = 0; i < sizes.size(); i++) {
            if (sizes[i] % 2 == 0) {
                // pair
                if (nb_even >= sizes[i]) {
                    nb_even -= sizes[i];
                    ans++;
                } else {
                    break;
                }
            } else {
                // impair
                if (nb_al_odd > 0 && nb_even >= sizes[i] - 1) {
                    nb_al_odd--;
                    nb_even -= (sizes[i] - 1);
                    ans++;
                } else {
                    if (nb_even > sizes[i]) {
                        ans++;
                        nb_even -= (sizes[i] + 1);
                        nb_al_odd++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"abbb", "ba", "aa"};
    vector<string> v2 = {"abc", "ab"};
    vector<string> v3 = {"cd", "ef", "a"};
    vector<string> v4 = {"c", "a", "aaa"};
    string s1 = "";
    string t1 = "";
    cout << solver.maxPalindromesAfterOperations(v1) << endl;
    cout << solver.maxPalindromesAfterOperations(v2) << endl;
    cout << solver.maxPalindromesAfterOperations(v3) << endl;
    cout << solver.maxPalindromesAfterOperations(v4) << endl;
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
