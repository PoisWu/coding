#include <iostream> 
#include <vector> 
#include <utility>  
#include <map>

using namespace std;

class Solution{
    public: 
        vector<vector<int> > threeSum(vector<int>& nums){
            vector<vector<int> > output = vector<vector<int> >();
            sort(nums.begin(),nums.end());
            if(nums.size()<3) return output;
                map<int,vector< pair<int,int> > > table = map<int,vector<pair<int,int> > >();
            for(int i=0; i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    int two_Sum = nums[i]+nums[j];
                    if(!table.count(two_Sum)){
                        table[two_Sum]=vector<pair<int,int> >();
                    } 
                    table[two_Sum].push_back(pair<int,int> (i,j));
                }
            }     
            for(int i = 0 ; i < nums.size(); i++){
                if(table.count( nums[i]*(-1) )){
                    vector<pair<int,int>>::iterator it;
                    for(it=table.begin(); it != table.end() ; it++){
                        
                    }
                }
            }

            return output;
            

        }
};

int main(){
    return 0;
}
