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
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        int i = digits.size() - 1;
        digits[i]++;
        do {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            i--;
        } while (i >= 0 && carry);
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {9};
    string s1 = "";
    string t1 = "";
    print_vector(solver.plusOne(v1));
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
