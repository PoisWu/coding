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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];


        int ret = 0;
        int rob = nums[1], norob = 0;

        // N [ ]
        for (int i = 2; i < n; i++) {
            int tmp = rob, n_tmp = norob;
            rob = n_tmp + nums[i];
            norob = max(tmp, n_tmp);
        }
        ret = max(rob, norob);

        rob = nums[0];
        norob = 0;
        for (int i = 1; i < n - 1; i++) {
            int tmp = rob, n_tmp = norob;
            rob = n_tmp + nums[i];
            norob = max(tmp, n_tmp);
        }
        ret = max(ret, max(rob, norob));
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {2, 3, 2};
    vector<int> v2 = {1, 2, 3, 1};
    cout << solver.rob(v1) << endl;
    cout << solver.rob(v2) << endl;
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
