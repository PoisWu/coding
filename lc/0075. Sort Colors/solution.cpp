#include "../include/helper.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n-1-i; j++){
                if (nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {2, 0 ,2,1,1,0};
    string s1 = "";
    string t1 = "";
    solver.sortColors(v1);
    print_vector(v1);
    return 0;
}

