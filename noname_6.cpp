#include <string>
#include <iostream>
#include <algorithm>  
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        //initiation
        if(numRows==1) return s; 
        char table[numRows][s.length()];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.length();j++){
                table[i][j]='\0';
            }
        }
        int i=0,j=0;
        int isdown=1;
        for(int x=0;x<s.length();x++){
            table[i][j]=s[x];
            if(isdown){
                i++;
            }else{
                i--;
                j++;
            }
            if(i==numRows-1){
                isdown=0;
            }else if(i==0){
                isdown=1;
            }
        }
        string out_put="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.length();j++){
                if(table[i][j]!='\0'){
                    out_put+=table[i][j];
                }
            }
        }
        cout << out_put<<endl;
        return out_put;
    }
};

int main(){
    Solution s = Solution();
    string test= "PAYPALISHIRING";
    s.convert(test,4);
}