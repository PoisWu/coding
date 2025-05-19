#include "../include/helper.h"

class Solution{
public: 
    string triangleType(vector<int>& nums){
        sort(nums.begin(), nums.end());
        if (nums[0]+nums[1]<= nums[2]){
            return "none";
        }

        if (nums[0] == nums[2]){
            return "equilateral";
        }

        if (nums[0]!=nums[1] && nums[1]!= nums[2]){
            return "scalene";
        }
        return "isosceles";
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

