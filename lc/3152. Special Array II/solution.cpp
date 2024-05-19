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
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> isSpecial;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                isSpecial.push_back(i);
            }
        }
        vector<bool> ret;
        for (auto query : queries) {
            auto low =
                lower_bound(isSpecial.begin(), isSpecial.end(), query[0]);
            if (low == isSpecial.end() || *low >= query[1]) {
                ret.push_back(true);
            } else {
                ret.push_back(false);
            }
        }
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {3, 4, 1, 2, 6};
    string s1 = "";
    string t1 = "";
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
