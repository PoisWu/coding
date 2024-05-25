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
    int leng_h;
    int leng_v;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        leng_h = board[0].size();
        leng_v = board.size();
        for (int i = 0; i < leng_v; i++) {
            for (int j = 0; j < leng_h; j++) {
                if (search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, string word, int x, int y, int idx)
    {
        if (x < 0 || x == leng_v || y < 0 || y == leng_h ||
            board[x][y] != word[idx])
            return false;
        if (idx == word.length() - 1)
            return true;
        char cur = board[x][y];
        board[x][y] = 0;
        bool found = search(board, word, x - 1, y, idx + 1) ||
                     search(board, word, x + 1, y, idx + 1) ||
                     search(board, word, x, y - 1, idx + 1) ||
                     search(board, word, x, y + 1, idx + 1);
        board[x][y] = cur;
        return found;
    }
};

int main()
{
    Solution solver;
    vector<vector<char>> v1 = {};

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
