/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:leet 34. Find First and Last Position of Element in Sorted Array
 * 
 * End data:07-04
 * Runtime:68.51%
 * Memory Usage:61.67%
 * cf https://www.youtube.com/watch?v=dVXy6hmE_0U&ab_channel=Errichto 
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    int first_pos(vector<int> & nums,int x){
        int n = nums.size();
        int first_pos = n;
        int low=0, high  = n-1;
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(nums[mid] >= x){
                first_pos = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return first_pos;
    }

    public:
        vector<int> searchRange(vector<int> & nums, int x){
            int fst = first_pos(nums,x);
            int last = first_pos(nums,x+1)-1;
            if(fst <=last){
                return {fst,last};
            }
            else{
                return {-1,-1};
            }
        };
};

int main(){
    Solution s = Solution();
    return 0;
}
