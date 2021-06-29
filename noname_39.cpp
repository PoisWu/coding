/**
 * Creater: Nonamefour
 * Creat data:2021-06-29
 * Purpose:leet 39.Comibnaiton Sum
 *
 * End data:
 */

#include<iostream> 
#include<vector>

using namespace std;

class Solution{
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
           return find(condidates,trg,condidate[condidate.size()-1].allCombination;
    }
};

int main(){
    
    return 0;
}
// condidate croissant
struct return_type {
    int isfound;
    vector<vector<int> > allCombination;
};

return_type find(vector<int> & condidate,int trg, int position_biggest){
    return_type result;
   if(trg<condiate[0]{
           if(trg==0){
                result.isfound=1;
                result.allCombination=vector<vector<int> >();
           }else{
                result.isfound=0;
           }
    }else{
        for(int i=0;i<=position_biggest;i++){
            return_type aux = find(condidate, trg-condidate[i],i)
            if(aux.isfound){
                for(vector<int> combination : aux.allCombination){
                    combination.push_back(condidate[i]);
                    result.allCombination.push_back(combination);
                    isfound=1;
                    }
            }
        }
    }
    return result;
    }
// candidates : int array given,
// combinationsum(trg)=fin(trg,max(candidates))
// find : trg,position_biggest_number_available -> 有無找到,{所有組合使得組合中的所有數字都小於biggest_number_available  sum = trg}
// 
// find 的遞迴關係：
//     1. trg < min(candidates) 
//         1.a trag = 0; -> 我們可以找到一種組合 這種組合是空集合
//         1.b trag !=0; -> 一定沒有一種組合
//     2. 遞迴
//          
//         find(trg-condidate[3],3)::candidate[3]
//         find(trg-3,3)::3
//         find(trg-2,2)::2
// 
