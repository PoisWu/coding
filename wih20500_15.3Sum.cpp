#include <iostream>
#include <vector>
#include <algorithm> //min

using namespace std;

class Solution{
    public:
         vector<vector<int>> threeSum(vector<int>& nums) {
                             vector<vector<int>> ans;
                             vector<int> v1;
                             int count = 0;

                             sort(nums.begin(), nums.end());

                             int numsln = nums.size();
                             if(numsln == 0 || numsln == 1){
                                 return ans;
                             }  

                             for(int i = 0; i < numsln; i++){
                                 for(int j = i + 1; j < numsln; j++){
                                     for(int k = j + 1; k < numsln; k++){
                                         if(nums[i] + nums[j] + nums[k] == 0){
                                            v1.clear(); 
                                            count = 0;
                                            v1.push_back(nums[i]);
                                            v1.push_back(nums[j]);
                                            v1.push_back(nums[k]);
                                            sort(v1.begin(), v1.end());

                                            
                                            for (vector<vector<int>>::size_type l = 0; l < ans.size(); l++ ){
                                                if(v1[0] == ans[l][0] && v1[1] == ans[l][1] && v1[2] == ans[l][2])
                                                   count++;
                                            }      
                                            if (count > 0) 
                                                break;    
                                            else   
                                                ans.push_back(v1);           
                                         }   
                                     }
                                 }
                             }
                             return ans;                                         
        }
};

int main(){
    Solution s = Solution();
    vector<int> vec1;
    vector<vector<int>> vec2;
    vec1.push_back(-1);
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(-1);
    vec1.push_back(-4);
    vec1.push_back(-2);
    vec1.push_back(-3);
    vec1.push_back(3);
    vec1.push_back(0);
    vec1.push_back(4);
    /*vec1 = [-1,0,1,2,-1,-4,-2,-3,3,0,4];*/

    //sort(vec1.begin(), vec1.end());
    
    vec2 = s.threeSum(vec1);

    cout << '[';
    for (vector<vector<int>>::size_type i = 0; i < vec2.size(); i++ ){
        cout << '[';
         for (vector<int>::size_type j = 0; j < vec2[i].size(); j++ ){
              cout << vec2[i][j];
              if (j < vec2[i].size() - 1)
              {
                 cout << ','; 
              }
         }
         cout << ']';
    }
    cout << ']';
}