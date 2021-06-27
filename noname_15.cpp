#include <iostream> 
#include <vector> 
#include <utility>  
#include <map>

using namespace std;


class Solution{
    public: 
        vector<vector<int> > threeSum(vector<int>& nums){
            vector<vector<int> > result = vector<vector<int> >();
            if(nums.size()<3) return result;
            sort(nums.begin(),nums.end());
            for(int i = 0; i<nums.size()-2;i++){
                if(i==0 || nums[i]!=nums[i-1]){
                    int start = i+1;
                    int end = nums.size()-1;
                    int repeat = 0;
                    while(start<=end){
                        if(nums[start] + nums[end] == nums[i]*(-1)){
                            if(repeat) start++;
                            else{
                                vector<int> tmp = vector<int>();
                                tmp.push_back(nums[i]);
                                tmp.push_back(nums[start]);
                                tmp.push_back(nums[end]);
                                result.push_back(tmp);
                                repeat=1;
                                start++;
                            }
                        }else{
                            if(nums[start] + nums[end] < nums[i]*(-1)){
                                repeat=0;
                                start++;
                            }else{
                                repeat=0;
                                end--;
                            }
                        }
                    }
                }
            }
            return result;


        }            
};

int main(){
    Solution s = Solution();
    vector<int> vec1;
    vector<vector<int> > vec2 = vector<vector<int> >();
    vec1.push_back(3);
    vec1.push_back(0);
    vec1.push_back(-2);
    vec1.push_back(-1);
    vec1.push_back(1);
    vec1.push_back(2);

    vec2 = s.threeSum(vec1);
    cout << '[';
    for (vector<vector<int> >::size_type i = 0; i < vec2.size(); i++ ){
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
    return 0;
}
