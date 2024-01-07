/**
 * Creater: Nonamefour
 * Creat data:2021-07-05
 * Purpose:leet 36.Valid Sudoku
 *
 * End data:07-04
 * Runtime:35.51%
 * Memory Usage:33.98%
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> tab = unordered_set<string>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                string charij = string(1, board[i][j]);
                if (charij != ".") {
                    bool row =
                        tab.find(charij + "in row" + to_string(i)) != tab.end();
                    bool col = tab.find(charij + "in column" + to_string(j)) !=
                               tab.end();
                    bool blo = tab.find(charij + "in block" + to_string(i / 3) +
                                        "-" + to_string(j / 3)) != tab.end();
                    if (row || col || blo)
                        return false;
                    else {
                        tab.insert(charij + "in row" + to_string(i));
                        tab.insert(charij + "in column" + to_string(j));
                        tab.insert(charij + "in block" + to_string(i / 3) +
                                   "-" + to_string(j / 3));
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s = Solution();
    return 0;
}
