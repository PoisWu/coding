#include "../include/helper.h"

class Solution{
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // The matrix is n*m
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0; j<m;j++){
            for (int = 0; i<n; i++){
                // compute dp[i][j] = min(dp[i-1])

            }
        }
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    /*cout << solver.<< endl;*/
    print_vector(v1);
    return 0;
}

