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
    uint32_t reverseBits(uint32_t n)
    {
        for (int i = 0; i < 16; i++) {
            int leftbit = 1 & (n >> (31 - i));
            int rightbit = 1 & (n >> i);
            int maskleft = ~(1 << (31 - i));
            int maskright = ~(1 << i);
            n = ((n & maskleft) & maskright) ^ (leftbit << i) ^
                (rightbit << (31 - i));
        }
        return n;
    }
};

int main()
{
    Solution solver;
    uint32_t n1 = 0;
    uint32_t n2 = 1;
    cout << solver.reverseBits(n1) << endl;
    cout << solver.reverseBits(n2) << endl;
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
