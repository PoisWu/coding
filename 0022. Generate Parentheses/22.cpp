/**
 * Creater: Nonamefour
 * Creat data:2021-06-28
 * Purpose:leet 22.Generate Parentheses
 *
 * End data:07-02
 * Runtime:
 *      0ms
 *      100%
 * Memory Usgage :
 *      13.5MB
 *      66.92%
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void aux(vector<string> &result,
             string partiel,
             int r_rest,
             int l_rest,
             int l_remin)
    {
        if (r_rest == 0)
            result.push_back(partiel);
        else {
            if (l_remin) {
                aux(result, partiel + ')', r_rest - 1, l_rest, l_remin - 1);
            }
            if (l_rest) {
                aux(result, partiel + '(', r_rest, l_rest - 1, l_remin + 1);
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result = vector<string>();
        string partiel = "";
        aux(result, partiel, n, n, 0);
        return result;
    }
};

int main()
{
    Solution s = Solution();
    vector<string> vec = s.generateParenthesis(3);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    return 0;
}
