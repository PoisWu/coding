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
    string maximumOddBinaryNumber(string s)
    {
        int nb_1 = 0;
        int nb_0 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                nb_0++;
            } else {
                nb_1++;
            }
        }
        return string(nb_1 - 1, '1') + string(nb_0, '0') + "1";
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "011001";
    cout << solver.maximumOddBinaryNumber(s1) << endl;
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
