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
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);
        int n = s.length();
        int i = 0;
        int ret = 0;

        for (int j = 0; j < n; j++) {
            count[s[j] - 'A']++;
            while (j - i + 1 - *max_element(count.begin(), count.end()) > k) {
                count[s[i] - 'A']--;
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    string s1 = "ABAB";
    string t1 = "";
    cout << solver.characterReplacement(s1, 2) << endl;
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
