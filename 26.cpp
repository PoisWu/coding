/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:leet 26.Remove Duplicates from Sorted Array
 * 
 * End data:07-04
 * Runtime:85.54%
 * Memory Usage:5.11%
 *		
 */

#include<iostream> 
#include<vector>

using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int> & nums){
            int k=1;
            for(int i = 1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]){
                    nums[k]=nums[i];
                    k++;
                }
            }
            return k;
        }
};

int main(){
    
    return 0;
}
