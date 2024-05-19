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
    int n;
    vector<vector<string>> ret;
    vector<string> board;

    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        board.clear();
        board.resize(n, string(n, '.'));
        dfs(0);
        return ret;
    }
    void dfs(int i)
    {
        if (i == n) {
            ret.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isValid(i, j)) {
                board[i][j] = 'Q';
                dfs(i + 1);
                board[i][j] = '.';
            }
        }
    }
    bool isValid(int row, int col)
    {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        int k = 1;
        while (row - k >= 0 && col - k >= 0) {
            if (board[row - k][col - k] == 'Q')
                return false;
            k++;
        }
        k = 1;
        while (row - k >= 0 && col + k < n) {
            if (board[row - k][col + k] == 'Q')
                return false;
            k++;
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
    print_2d_vector(solver.solveNQueens(4));
    print_2d_vector(solver.solveNQueens(9));
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
