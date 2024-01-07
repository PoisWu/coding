/**
 * Creater: Nonamefour
 * Creat data:2021-07-05
 * Purpose:leet 39.Comibnaiton Sum
 *
 * End data:07-06
 */


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void aux(vector<int> &nums,
         vector<vector<int>> &result,
         vector<int> &partial,
         int pos,
         int target)
{
    if (target == 0) {
        result.push_back(partial);
        return;
    }
    if (target < 0 || pos == nums.size())
        return;
    int pos_next = pos;
    while (pos_next < nums.size() && nums[pos_next] == nums[pos])
        pos_next++;
    for (int i = pos; i < pos_next; i++) {
        partial.push_back(nums[pos]);
        aux(nums, result, partial, pos_next,
            target - (i - pos + 1) * nums[pos]);
    }
    for (int i = pos; i < pos_next; i++)
        partial.pop_back();
    aux(nums, result, partial, pos_next, target);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result = vector<vector<int>>();
    vector<int> partial = vector<int>();
    aux(candidates, result, partial, 0, target);
    return result;
}

int main()
{
    return 0;
}
