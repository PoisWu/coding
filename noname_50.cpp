/**
 * Creater: Nonamefour
 * Creat data:2021-07-09
 * Purpose:leet 50.Pow(x,n)
 * 
 * End data:07-09
 * Runtime:
 * Memory Usage:
 *  cf: https://leetcode.com/problems/powx-n/discuss/1326760/C%2B%2B-or-faster-100-or-iterative
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

double myPow(double x,int y){
    double a=x;
    bool ne=y<0;
    long n = abs(y);
    double ans = 1;
    while(n){
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ne?1.0/ans:ans;
}


int main(){
    return 0;
}
