#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
    public:
        long reverse(long x){
            if(x==0) return 0;
            long result=0;
            long signe=0;
            if(x>0){
                signe=1;
            }else{
                signe=-1;
                x=-x;
            }
            while(x>0){
                result=result*10+x%10;
                cout << result <<endl;
                x=x/10;
            }
            if(result>0x7fffffff) return 0;
            return signe*result;
        }
};

int main(){
    Solution s = Solution();
    long x = 1534236469;
    long ok=s.reverse(x);
    cout << ok <<endl;
}

