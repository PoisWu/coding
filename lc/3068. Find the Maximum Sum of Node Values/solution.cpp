#include "../include/helper.h"
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta; 
        long long ret = 0;
        for (int i = 0; i<n; i++){
            delta.push_back((nums[i]^k)-nums[i]);
            ret += nums[i];
        }
        sort(delta.begin(), delta.end(), greater<int>());

        for (int  i =0; i<delta.size()-1; i+=2 ){
            if (delta[i]+delta[i+1]>0){
                ret += (delta[i]+delta[i+1]);
            }
        }
        return ret;
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

