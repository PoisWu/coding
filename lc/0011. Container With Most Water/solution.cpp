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
    int maxArea(vector<int> heights)
    {
        int left = 0;
        int right = heights.size() - 1;
        int ret = 0;
        while (left < right) {
            ret = max((right - left) * min(heights[left], heights[right]), ret);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
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
