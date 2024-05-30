#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
using lli = long long int;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            if (isalpha(s[l]) != isalpha(s[r])) {
                return false;
            }
            if (isalpha(s[l])) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
            } else {
                if (s[l] != s[r]) {
                    return false;
                }
            }

            l++;
            r--;
        }
        return true;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "0P";
    string t1 = "";
    cout << solver.isPalindrome(s1) << endl;
    return 0;
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
