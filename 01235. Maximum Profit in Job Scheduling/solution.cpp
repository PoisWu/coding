#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

class Solution
{
public:
    int jobScheduling(vector<int> &startTime,
                      vector<int> &endTime,
                      vector<int> &profit)
    {
        int n = startTime.size();
        vector<pair<int, pair<int, int> > > jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back(
                make_pair(startTime[i], make_pair(endTime[i], profit[i])));
        }
        sort(jobs.begin(), jobs.end());
        int dp[n];
        for (int i = n - 1; i >= 0; i--) {
            int end_i = jobs[i].second.first;
            int profile_i = jobs[i].second.second;
            auto upper = upper_bound(advance(jobs, i + 1), jobs.end(),
                                     make_pair(end_i, make_pair(0, 0)));
            if (upper != jobs.end()) {
                int j = distance(jobs.begin(), upper);
                dp[i] = max(profile_i + dp[j], dp[i + 1]);
            } else {
                dp[i] = max(profile_i, (i == n - 1) ? -1 : dp[i + 1]);
            }
        }
        return dp[0];
    }
};
