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
    int minimumLength(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            char a = s[left];
            if (s[right] != a) {
                break;
            }
            int ltmp = left;
            int rtmp = right;
            while (ltmp <= right) {
                if (s[ltmp] == a) {
                    ltmp++;
                } else {
                    break;
                }
            }
            while (rtmp >= left) {
                if (s[rtmp] == a) {
                    rtmp--;
                } else {
                    break;
                }
            }
            left = ltmp;
            right = rtmp;
        }
        return max(0, right - left + 1);
    }
};

int main()
{
    Solution solver;
    string s2 = "ca";
    string s1 = "cabaabac";
    string t1 = "aabccabba";
    cout << solver.minimumLength(s2) << endl;
    cout << solver.minimumLength(s1) << endl;
    cout << solver.minimumLength(t1) << endl;
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
