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

using namespace std;


class Solution
{
private:
    static const int mod = 1000000007;

public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            // pick i as the center pint
            for (int j = 1; j + i < n && i - j >= 0; j++) {
                if (s[i - j] == s[i + j]) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                ans++;
                cout << i << " " << i + 1 << endl;
                for (int j = 1; i + 1 + j < n && i - j >= 0; j++) {
                    if (s[i - j] == s[i + 1 + j]) {
                        ans++;
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
    string s1 = "abc";
    string t1 = "aaaaa";
    cout << solver.countSubstrings(s1) << endl;
    cout << solver.countSubstrings(t1) << endl;
    return 0;
}
