/**
 * Creater: Nonamefour
 * Creat data:2021-06-27
 * Purpose: Leet No.16 3sum Closest
 *
 * End data:06-27
 */

#include<iostream> 
#include<vector>
#include<cmath>

using namespace std;

class Solution{
    public:
        int threeSumClosest(vector<int> &nums, int target){
            sort(nums.begin(),nums.end());
            int found = nums[0]+nums[1]+nums[2];
            if(found==target) return target;
            for(int i=0 ; i < nums.size()-2; i++){
                int start = i+1;
                int end = nums.size()-1;
                while(start<end){
                    int sum=nums[i]+nums[start]+nums[end];
                    if(sum == target) return target;
                    else{
                        if (sum < target ) start++;
                        else end--;
                    }
                    if(abs(sum-target)<abs(found-target)) found = sum;
                }
            }
            return found;
        }

};

int main(){
    vector<int> tab = vector<int>();
    tab.push_back(-1);
    tab.push_back(2);
    tab.push_back(1);
    tab.push_back(-4);
    Solution s = Solution();
    cout << s.threeSumClosest(tab,1) <<endl;
    return 0;
}
