/**
 * Creater: Nonamefour
 * Creat data:2021-07-09
 * Purpose:leet 300.Longest increasing Subswquence
 *
 * End data:07-09
 * Runtime:99.07%
 * Memory Usage:60.30%
 *		key word: Patience sorting
 *		rf: https://www.youtube.com/watch?v=l2rCz7skAlk&ab_channel=HuaHua
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &v)
{
    vector<int> dp;
    for (int x : v) {
        auto it = lower_bound(begin(dp), end(dp), x);
        if (it == end(dp))
            dp.push_back(x);
        else
            *it = x;
    }
    return dp.size();
}

int main()
{
    return 0;
}
