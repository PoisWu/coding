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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0) {
            return {nums[0]};
        }

        vector<int> ret(n, 0);
        ret[0] = nums[0];
        for (int i = 1; i < n; i++) {
            // compute prefix
            ret[i] = nums[i] * ret[i - 1];
        }

        // computing surfix
        for (int i = n - 2; i >= 0; i--) {
            nums[i] = nums[i + 1] * nums[i];
        }

        int pre = ret[0];
        for (int i = 0; i < n; i++) {
            int tmp = ret[i];
            ret[i] = (i - 1 >= 0 ? pre : 1) * (i + 1 < n ? nums[i + 1] : 1);
            pre = tmp;
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {-1, 1, 0, -3, 3};
    print_vector(solver.productExceptSelf(v1));
    print_vector(solver.productExceptSelf(v2));
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
