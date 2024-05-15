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
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ret = 0;
        int i = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                count++;
                while (count > k) {
                    if (nums[i] == 0) {
                        count--;
                    }
                    i++;
                }
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    string s1 = "";
    string t1 = "";
    cout << solver.longestOnes(v1, 2) << endl;
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
