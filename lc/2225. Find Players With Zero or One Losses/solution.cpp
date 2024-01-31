#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lose;
        for (auto match : matches) {
            lose[match[1]]++;
        }

        vector<int> nolose;
        vector<int> loseonce;
        for (auto match : matches) {
            int winner = match[0];
            int loser = match[1];
            if (lose.find(winner) == lose.end()) {
                nolose.push_back(winner);
                lose[winner] = 2;
            }
            if (lose[loser] == 1) {
                loseonce.push_back(loser);
            }
        }
        sort(nolose.begin(), nolose.end());
        sort(loseonce.begin(), loseonce.end());
        return {nolose, loseonce};
    }
};
