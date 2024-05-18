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
    double myPow(double x, int n)
    {
        if (x == 0) {
            return 0;
        }
        long long np = n;
        if (np < 0) {
            x = 1 / x;
            np = -np;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ret = 1;
        while (np) {
            if (np % 2) {
                ret = ret * x;
            }
            x = x * x;
            np = np / 2;
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
    cout << solver.myPow(2, 10) << endl;
    cout << solver.myPow(2, -2) << endl;
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
