#include <algorithm>
#include <array>
#include <bitset>
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
    int rangeBitwiseAnd(int left, int right)
    {
        if (!left) {
            return 0;
        }
        if (left == right) {
            ret
        }
        int leading_bit_pos = 0;
        for (int i = 31; i >= 0; i--) {
            if ((left >> i) & 1) {
                leading_bit_pos = i;
                break;
            }
        }
        if (right < (1 << (leading_bit_pos + 1))) {
            return 1 << leading_bit_pos;
        } else {
            return 0;
        }
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.rangeBitwiseAnd(5, 7) << endl;
    cout << solver.rangeBitwiseAnd(0, 0) << endl;
    cout << solver.rangeBitwiseAnd(0, 1) << endl;
    cout << solver.rangeBitwiseAnd(1, 2147483647) << endl;
    cout << solver.rangeBitwiseAnd(2<<31)-1,(2<<16)-1)<< endl;
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
