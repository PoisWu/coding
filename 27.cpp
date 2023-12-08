/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:leet 27.Remove Element
 * 
 * End data:07-04
 * Runtime:100%
 * Memory Usage:31.79%
 *		
 */

#include<iostream> 
#include<vector>

using namespace std;

class Solution{
    public:
        int removeElement(vector<int> & nums,int val){
            int k = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=val){
                    nums[k++]=nums[i];
                }
            }
            return k;
        }
};

int main(){
    Solution s = Solution();
    return 0;
}
