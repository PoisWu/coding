/**
 * Creater: Nonamefour
 * Creat data:2021-07-06
 * Purpose:leet 45. Jump Game II
 * 
 * End data:07-08
 * Runtime:12.78%
 * Memory Usage:44.4%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

int jump(vector<int> & v){
   int n = v.size();
   int tab[n];
   for(int i = 0;i<n;i++) tab[i]=n;
   tab[0]=0;
   for(int i = 0; i<n; i++){
       for(int j=0;j<v[i]&&j+i+1<n;j++){
           tab[i+j+1]=min(tab[i]+1,tab[i+j+1]);
       }
   }
   return tab[n-1];
}

int main(){
    vector<int> v = {2,3,1,1,4};
    cout << jump(v) <<endl;
    v = {2,3,0,1,4};
    cout << jump(v) << endl;
    return 0;
}
