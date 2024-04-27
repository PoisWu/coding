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
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        unordered_map<char, int> fq;
        for (int i = 0; i < n; i++) {
            fq[t[i]]--;
        }
        int nb_c = fq.size();
        int minLength = m + 1;
        int _start;
        int j = -1;
        // (j, i]
        for (int i = 0; i < m; i++) {
            if (fq.find(s[i]) != fq.end()) {
                if ((++fq[s[i]]) == 0) {
                    nb_c--;
                }
                while (nb_c == 0) {
                    if (minLength > i - j) {
                        minLength = i - j;
                        _start = j + 1;
                    }
                    j++;
                    if (fq.find(s[j]) != fq.end()) {
                        if (--fq[s[j]] < 0) {
                            nb_c++;
                        }
                    }
                }
            }
        }

        return minLength == m + 1 ? "" : s.substr(_start, minLength);
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << solver.minWindow(s1, t1) << endl;
    string s2 = "";
    string t2 = "ABC";
    cout << solver.minWindow(s2, t2) << endl;
    string s3 = "ABC";
    string t3 = "ABC";
    cout << solver.minWindow(s3, t3) << endl;
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
