/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:33 Search in Rotated Sorted Array
 * 
 * End data:07-04
 * Runtime:74.05%
 * Memory Usage:72.92%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
        int search(vector<int> &nums,int target){
            int l=0,r=nums.size()-1;
            if(nums[r]==target) return r;
            if(nums[l]==target) return l;
            while((r-l)>1){
                int mid = (l+r)/2;
                if(nums[mid]==target) return mid;

                if(nums[l]<nums[r]){
                    if(target<nums[mid]) r=mid;// l t m r
                    else l=mid;
                }else{
                    if(nums[mid]<nums[r]){
                    // l       p   m      r   
                        if(target>nums[l]) r = mid;
                        else{
                            if(target<nums[mid]) r=mid;
                            else l=mid;
                        }
                    }else{
                        // l m p r 
                        if(target <nums[r]) l = mid;
                        else{
                            if(target<nums[mid]) r = mid;
                            else l = mid;
                        }
                    }
                }
            }
            if(nums[r]==target) return r;
            if(nums[l]==target) return l;
            return -1;
        }
};

int main(){
    Solution s = Solution();
    return 0;
}
