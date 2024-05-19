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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < n - 1; i++) {
            ret.push_back(matrix[0][i]);
        }
        int x = 0;
        int y = n - 1;
        int ver = m - 1;
        int hor = n - 1;
        int hor_turn = false;
        int step = 1;
        while ((hor_turn && hor) || (!hor_turn && ver)) {
            if (hor_turn) {
                for (int i = 0; i < hor; i++) {
                    ret.push_back(matrix[x][y]);
                    y += step;
                }
                hor--;
                hor_turn = false;
            } else {
                for (int i = 0; i < ver; i++) {
                    ret.push_back(matrix[x][y]);
                    x += step;
                }
                ver--;
                hor_turn = true;
                step = step * -1;
            }
        }
        ret.push_back(matrix[x][y]);
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v2 = {};
    v2.push_back({1, 2, 3, 4});
    v2.push_back({5, 6, 7, 8});
    v2.push_back({9, 10, 11, 12});
    print_vector(solver.spiralOrder(v2));
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
