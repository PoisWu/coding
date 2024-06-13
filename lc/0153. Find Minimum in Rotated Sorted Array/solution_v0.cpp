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
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[left] < nums[right]) {
                return nums[left];
            } else {
                if (nums[mid] >= nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    cout << solver.findMin(v1) << endl;
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
