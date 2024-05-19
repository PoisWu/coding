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
    bool checkInclusion(string s1, string s2)
    {
        vector<int> table1(26, 0);
        for (char c : s1) {
            alphas1[c - 'a']++;
        }
        vector<int> table2(26, 0);
        for (int j = 0; j < s2.length(); j++) {
            table2[s2[j - 'a']]++;
            if (j >= n - 1) {
                if (table1 == table2) {
                    return true;
                }
                table2[s2[j - n + 1]]--;
            }
        }
        return false;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.checkInclusion("ab", "eidbaooo") << endl;
    cout << solver.checkInclusion("ab", "eidboaoo") << endl;
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
