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
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        //
        while (l < r) {
            int mid = l + (r - l) / 2;  // close l
            if ((nums[mid] >= nums[0]) == (target >= nums[0])) {
                if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                // B   P t    S
                if (target >= nums[0]) {
                    // B  t  P     S
                    r = mid - 1;
                } else {
                    // B    P t    S
                    l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 3};
    cout << solver.search(v1, 3) << endl;
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
