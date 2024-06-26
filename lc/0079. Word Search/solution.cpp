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
    int m;
    int n;
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool search(vector<vector<char>> &board, string word, int x, int y, int idx)
    {
        if (idx == word.length()) {
            return true;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[idx]) {
            return false;
        }
        char c = board[x][y];
        board[x][y] = '0';
        bool a = false;
        a = a || search(board, word, x + 1, y, idx + 1);
        a = a || search(board, word, x - 1, y, idx + 1);
        a = a || search(board, word, x, y + 1, idx + 1);
        a = a || search(board, word, x, y - 1, idx + 1);
        board[x][y] = c;
        return a;
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
