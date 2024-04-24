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
    int maxArea(vector<int> hights)
    {
        int s = 0;
        int t = hights.size() - 1;
        int res = 0;

        while (s < t) {
            // look interval of [s, t]
            res = max(res, min(hights[t], hights[s]) * (t - s));
            if (hights[t] < hights[s]) {
                t--;
            } else {
                s++;
            }
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solver.maxArea(v1) << endl;
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
