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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool valid = true;
        for (int i = 0; i < 9; i++) {
            valid = valid && checkrow(board, i);
            valid = valid && checkcolumn(board, i);
            valid = valid && checkblock(board, i / 3, i % 3);
        }
        return valid;
    }
    bool checkrow(vector<vector<char>> &board, int row)
    {
        vector<bool> freq(9, false);
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.') {
                continue;
            }
            int c = board[row][i] - '1';
            if (freq[c]) {
                return false;
            } else {
                freq[c] = true;
            }
        }
        return true;
    }
    bool checkcolumn(vector<vector<char>> &board, int column)
    {
        vector<bool> freq(9, false);
        for (int i = 0; i < 9; i++) {
            if (board[i][column] == '.') {
                continue;
            }
            int c = board[i][column] - '1';
            if (freq[c]) {
                return false;
            } else {
                freq[c] = true;
            }
        }
        return true;
    }
    bool checkblock(vector<vector<char>> &board, int r, int w)
    {
        vector<bool> freq(9, false);
        for (int i = 0; i < 9; i++) {
            int x = 3 * r + i / 3;
            int y = 3 * w + i % 3;
            if (board[x][y] == '.') {
                continue;
            }
            int c = board[x][y] - '1';
            if (freq[c]) {
                return false;
            } else {
                freq[c] = true;
            }
        }
        return true;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.<< endl;
    print_vector(solver.);
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
