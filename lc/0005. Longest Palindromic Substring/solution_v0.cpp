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
private:
    static const int mod = 1000000007;

public:
    string longestPalindrome(string s)
    {
        string t = s;
        t = "#";
        for (char c : s) {
            t.push_back(c);
            t.push_back('#');
        }

        int n = t.length();
        vector<int> p(n);
        int rightmost = -1;
        int center = -1;
        int maxlen = -1;
        int start = -1;

        for (int i = 0; i < n; i++) {
            int r = 0;
            if (i <= rightmost) {
                int j = 2 * center - i;
                r = min(p[j], rightmost - i);
            }
            while (i - r >= 0 && i + r < n && t[i - r] == t[i + r]) {
                r++;
            }
            p[i] = r - 1;
            if (i + p[i] > rightmost) {
                center = i;
                rightmost = i + p[i];
            }
            if (maxlen < p[i]) {
                maxlen = p[i];
                start = i - p[i];
            }
        }
        // cout  << start << " " << maxlen << endl;
        return s.substr(start / 2, maxlen);
    }
};

int main()
{
    Solution solver;
    string s1 = "babad";
    string t1 = "cbba";
    cout << solver.longestPalindrome(s1) << endl;
    cout << solver.longestPalindrome(t1) << endl;
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
