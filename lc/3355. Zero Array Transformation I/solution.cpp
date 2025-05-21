#include "../include/helper.h"

class Solution{
public: 
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries){
        map<int, int> tab; 
        for (auto v: queries){
            tab[v[0]]++;
            tab[v[1]+1]--;
        }
        int n = nums.size();
        int cnt = 0;
        int currn_idx = 0;
        for (auto it: tab){
            while (currn_idx < n && currn_idx<it.first){
                if (nums[currn_idx] > cnt){
                    return false;
                }
                currn_idx++;
            }
            cnt += it.second;
        }

        for (;currn_idx<n; currn_idx++){
            if (nums[currn_idx]>cnt){
                return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {1,0,1};
    vector<vector<int>> q1;
    q1.push_back({0,2});
    cout << solver.isZeroArray(v1, q1) << endl;
    return 0;
}

