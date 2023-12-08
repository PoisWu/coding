/**
 * Creater: Nonamefour
 * Creat data:2021-07-05
 * Purpose:leet 38.Count and Say
 * 
 * End data:07-05
 * Runtime:71.49%
 * Memory Usage:85.80%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

string countAndSay(int n){
    if(n==1){
        return "1";
    }
    if(n==2){
        return "11";
    }
    string res = "11";
    for(int i = 2;i<n;i++){
        int nb;
        char c;
        string aux;
        for(int j = 0;j<res.length();j++){
            if(j==0){
                aux="";
                nb=1;
                c=res[j];
            }
           else if(j==res.length()-1){
                if(res[j]==c){
                    nb++;
                    aux+=to_string(nb);
                    aux+=string(1,c);
                }else{
                    aux+=to_string(nb);
                    aux+=string(1,c);
                    aux+="1";
                    aux+=string(1,res[j]);
                }
            }
            else{
                if(res[j]==c) nb++;
                else{
                    aux+=to_string(nb);
                    aux+=string(1,c);
                    nb=1;
                    c=res[j];
                }
            }
        }
        res=aux;
    }
    return res;
}

int main(){
    cout<<countAndSay(4)<<endl;
    return 0;
}
