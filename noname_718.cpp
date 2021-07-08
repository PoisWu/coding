/**
 * Creater: Nonamefour
 * Creat data:2021-07-08
 * Purpose:718. Maximun Length of Repeated Subarray
 * 
 * End data:07-08
 * Runtime:63.32%
 * Memory Usage:96.50%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

int findLength(vector<int> &v1,vector<int> &v2){
    int n = v1.size();
    int m = v2.size();
    int tab[m];
    int maxL=0;
    for(int j=0;j<m;j++){// v1 end with 0, v2 end at j
        tab[j]=(v1[0]==v2[j])? 1 : 0;
        maxL=max(maxL,tab[j]);
    }
    for(int i=1;i<n;i++){
        for(int j=m-1;j>-1;j--){
            if(j==0){
                tab[j]=(v1[i]==v2[j])?1:0;
            }
            else{
                tab[j]=(v1[i]==v2[j])?tab[j-1]+1:0;
            }
            maxL=max(maxL,tab[j]);
        }
    }
    return maxL;
}

int main(){
    vector<int> v1={1,2,3,2,1};
    vector<int> v2={3,2,1,4,7};
    cout << findLength(v1,v2) <<endl;
    
    return 0;
}
