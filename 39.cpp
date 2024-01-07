/**
 * Creater: Nonamefour
 * Creat data:2021-06-29
 * Purpose:leet 39.Comibnaiton Sum
 *
 * End data:07-05
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
    partial.push_back(nums[pos]);
    aux(nums, result, partial, pos, target - nums[pos]);
    partial.pop_back();
    aux(nums, result, partial, pos + 1, target);
}

vector<vector<int>> combinationSUm(vector<int> &candidates, int target)
{
    vector<vector<int>> result = vector<vector<int>>();
    vector<int> partial = vector<int>();
    aux(candidates, result, partial, 0, target);
    return result;
}

int main()
{
    return 0;
}
