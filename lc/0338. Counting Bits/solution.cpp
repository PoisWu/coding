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
    vector<int> countBits(int n)
    {
        vector<int> ret = {0};
        int bound = 1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            ret.push_back(1 + ret[cur]);
            cur++;
            if (cur == bound) {
                cur = 0;
                bound = bound * 2;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    print_vector(solver.countBits(3));
    print_vector(solver.countBits(5));
    print_vector(solver.countBits(8));
    print_vector(solver.countBits(0));
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
