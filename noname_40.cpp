/**
 * Creater: Nonamefour
 * Creat data:2021-07-05
 * Purpose:leet 39.Comibnaiton Sum
 *
 * End data:07-05
 */


#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

void aux(vector<int>& nums,vector<vector<int>> & result, vector<int> & partial, int pos, int target){
    if(target==0){
        result.push_back(partial);
        return;
    }
    if(target<0 || pos==nums.size()) return ;
    partial.push_back(nums[pos]);
    int pos_next=pos;
    while(pos_next<nums.size() && nums[pos_next]==nums[pos]) pos_next++;
    aux(nums,result,partial,pos_next,target-nums[pos]);
    partial.pop_back();
    aux(nums,result,partial,pos_next,target);
}

vector<vector<int>> combinationSum2(vector<int> & candidates,int target){
    sort(candidates.begin(),candidates.end());

    vector<vector<int>> result = vector<vector<int>>();
    vector<int> partial = vector<int>();
    aux(candidates,result,partial,0,target);
    return result;
}

int main(){

    return 0;
}
