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
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n == 0 || n == 1) {
            return n;
        }
        // [start, end[
        int start = 0;
        int end = 1;
        int res = 0;
        unordered_map<char, int> m;
        m[s[start]] = start;
        while (end < n) {
            if (m.find(s[end]) != m.end() && m[s[end]] >= start) {
                res = max(res, end - start);
                start = m[s[end]] + 1;
            }
            m[s[end]] = end;
            end++;
        }
        res = max(res, end - start);
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "abcabcbb";
    string s2 = "pwwkew";
    string s3 = "bbbbb";
    string s4 = "abba";
    string s5 = "tmmzuxt";
    cout << solver.lengthOfLongestSubstring(s1) << endl;
    cout << solver.lengthOfLongestSubstring(s2) << endl;
    cout << solver.lengthOfLongestSubstring(s3) << endl;
    cout << solver.lengthOfLongestSubstring(s4) << endl;
    cout << solver.lengthOfLongestSubstring(s5) << endl;
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
