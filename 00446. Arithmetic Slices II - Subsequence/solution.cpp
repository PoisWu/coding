#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n][n];
        map<long long, vector<int> > num_pos;
        for (int i = 0; i < n; i++) {
            if (num_pos.count((long long) nums[i])) {
                num_pos[(long long) nums[i]].push_back(i);
            } else {
                num_pos[(long long) nums[i]] = {i};
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = 0;
                long long n_pre = 2 * (long long) nums[i] - (long long) nums[j];
                if (num_pos.count(n_pre)) {
                    for (auto pre : num_pos[n_pre]) {
                        if (pre < i) {
                            dp[i][j] += dp[pre][i] + 1;
                        }
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};
