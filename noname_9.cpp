#include<iostream>

using namespace std;

class Solution{
    public:
        bool isPalindrome(int x){
            if(x<0) return false;
            if(x==0) return true;
            int byte[32]={0};
            int i = 0;
            while(x>0){
                byte[i]=x%10;
                x=x/10;
                i++;
            }
            i--;
            int j=0;
            while(i>=j){
                if(byte[i]!=byte[j]) return false;
                i--;
                j++;
            }
            return true;
        }
};

int main(){
    Solution s = Solution();
    cout << s.isPalindrome(123) << endl;
    cout << s.isPalindrome(321) << endl;
    cout << s.isPalindrome(-123) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(321123) << endl;
}
