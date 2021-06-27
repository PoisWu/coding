/**
 * Creater: Nonamefour
 * Creat data:2021-06-27
 * Purpose:leet 17. Letter Combinations of a Phone Number
 *
 * End data:
 */

#include<iostream> 
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
       vector<string> letterCombinations(string digits){
           vector<string> vec = vector<string>();
           if(digits.length()==0) return vec;
           vector<string> tab = vector<string>();
           tab.push_back("abc");
           tab.push_back("def");
           tab.push_back("ghi");
           tab.push_back("jkl");
           tab.push_back("mno");
           tab.push_back("pqrs");
           tab.push_back("tuv");
           tab.push_back("wxyz");
           queue<string> que = queue<string>();
           for(int i = 0; i<digits.length();i++){
               int idx= digits[i]-'2';
               if(i==0){
                   for(int j = 0 ; j<tab[idx].length();j++){
                        que.push(string(1,tab[idx][j]));
                   }
               }else{
                   int quesize=que.size();
                   for(int x = 0; x<quesize;x++){
                       string s = que.front();
                       que.pop();
                       for(int j=0;j<tab[idx].length();j++){
                           que.push(s+tab[idx][j]);
                       }
                   }
               }
           }
           while(!que.empty()){
               vec.push_back(que.front());
               que.pop();
           }
           return vec;
       }
};

int main(){
    Solution s = Solution();
    string digits="23";
    vector<string> result = s.letterCombinations(digits);
    for(int i = 0 ; i<result.size();i++){

        cout << result[i] << endl;
    }
    return 0;
}
