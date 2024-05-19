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
    long long sumDigitDifferences(vector<int> &nums)
    {
        // building trie
        int nb_digit = 0;
        int x = nums[0];
        while (x) {
            nb_digit++;
            x = x / 10;
        }
        vector<vector<int>> tab(nb_digit, vector<int>(10, 0));
        for (int x : nums) {
            for (int i = 0; i < nb_digit; i++) {
                tab[i][x % 10]++;
                x = x / 10;
            }
        }
        long long ret = 0;
        for (int i = 0; i < nb_digit; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = j + 1; k < 10; k++) {
                    ret += tab[i][j] * tab[i][k];
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {13, 23, 12};
    cout << solver.sumDigitDifferences(v1) << endl;
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
