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
private:
    static const int mod = 1000000007;

public:
    void setZeros(vector<vector<int>> &matrix)
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        bool rowZero = false;
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r != 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }
        for (int r = 1; r < ROW; r++) {
            for (int c = 1; c < COL; c++) {
                if (matrix[r][0] * matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < ROW; i++) {
                matrix[i][0] = 0;
            }
        }

        if (rowZero) {
            for (int j = 0; j < COL; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
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
