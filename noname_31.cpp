/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:leet 31.Next Permutation
 * 
 * End data:07-02
 * Runtime:79.16%
 * Memory Usage:71.97%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
        void nextPermutation(vector<int> &nums){
           int end = nums.size()-1;
           while(end>0 && nums[end-1]> nums[end]) end --;
           if(end==0){
               reverse(nums.begin(),nums.end());
               return;
           }
           reverse(nums.begin()+end,nums.end());
           int pt = end-1;
           while(nums[pt]<nums[end]) end ++;
           int aux = nums[end];
           nums[end]=nums[end-1];
           nums[end-1]=aux;
           return;
        }
};

int main(){
    Solution s = Solution();
    vector<int> vec = vector<int>();
    string stg = "123";
    for(int i=0;i<stg.length();i++){
        vec.push_back(stg[i]-'0');
    }
    s.nextPermutation(vec);
    for(int i = 0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    return 0;
}
