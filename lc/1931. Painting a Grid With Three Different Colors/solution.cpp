#include "../include/helper.h"
#include <cmath>

class Solution{
    long long M = 1e9+7;
public: 
    int colorTheGrid(int m, int n){
        vector<int> cand;

        for(int i = 0; i<pow(3, m); i++){
            int flag = 1;
            vector<int> tmp;
            int cur = i;
            for (int j = 0; j<m; j++){

                if (!tmp.empty() && tmp.back() == cur%3){
                    flag = 0;
                    break;
                }
                tmp.push_back(cur%3);
                cur = cur/3;
            }
            if (flag)
                cand.push_back(i);
        }
        int k = cand.size();

        vector<long long> dp(k, 1);
        vector<long long> dp_new(k, 0);

        for (int i = 1; i<n; i++){
            for (int state_new_idx = 0; state_new_idx < k; state_new_idx++){
                dp_new[state_new_idx] = 0;
                for (int state_old_idx = 0; state_old_idx <k ; state_old_idx++){
                    if (checkOkay(cand[state_new_idx], cand[state_old_idx], m)){
                        dp_new[state_new_idx] = (dp_new[state_new_idx] + dp[state_old_idx]) % M;
                    }
                }
            }
            swap(dp, dp_new);
        }

        long long ret = 0;
        for (int i = 0; i<k; i++){
            ret = (ret + dp[i]) %M;
        }
        return ret;
    }

    bool checkOkay(int s, int t, int m){
        for (int i = 0; i<m; i++){
            if (s%3 == t%3){
                return false;
            }
            s /=3;
            t /=3;
        }
        return true;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.colorTheGrid(3, 1) << endl;
    cout << solver.colorTheGrid(1, 2) << endl;
    cout << solver.colorTheGrid(5, 5) << endl;
    /*cout << solver.<< endl;*/
    print_vector(v1);
    return 0;
}

