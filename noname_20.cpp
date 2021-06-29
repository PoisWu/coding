/**
 * Creater: Nonamefour
 * Creat data:2021-06-28
 * Purpose:leet 20.Valid Parentheses
 *
 * End data:06-28
 */

#include<iostream> 
#include<stack>

using namespace std;

class Solution{
    public:
        bool isValid(string s){
            stack<char> stk = stack<char>();
            if(s.length()%2==1) return false;
            for(int i = 0 ; i < s.length() ; i++){
                switch(s[i]){
                    case ')':
                        if(stk.top()=='(') stk.pop();
                        else return false;
                        break;
                    case ']':
                        if(stk.top() == '[') stk.pop();
                        else return false;
                        break;
                    case '}':
                        if(stk.top() == '{') stk.pop();
                        else return false;
                        break;
                    default:
                        stk.push(s[i]);
                }
            }
            return stk.empty();
        }
};


int main(){
    Solution s = Solution();
    s.isValid("}(");
    return 0;
}
