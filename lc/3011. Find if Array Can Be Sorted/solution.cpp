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
    int countNbbit(int n)
    {
        int cnt = 0;
        while (n > 0) {
            if (n & 1) {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }

public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (countNbbit(nums[j]) != countNbbit(nums[j + 1])) {
                        return false;
                    }
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {3, 16, 8, 4, 2};
    vector<int> v2 = {1, 2, 3, 4, 5};

    cout << solver.canSortArray(v1) << endl;
    cout << solver.canSortArray(v2) << endl;

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
