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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set2;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        for (int x : nums2) {
            if (set1.find(x) != set1.end()) {
                set2.insert(x);
            }
        }
        return vector<int>(set2.begin(), set2.end());
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    print_vector(solver.intersection(v1, v2));
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
