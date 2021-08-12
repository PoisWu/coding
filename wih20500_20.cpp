#include <iostream>
#include<stack>

using namespace std;

class Solution{
    public:
        bool isValid(string s) {
        stack<char> stk;
        for(char i:s)
        {
            switch(i)
            {
                case '(': stk.push(')'); break;
                case '{': stk.push('}'); break;
                case '[': stk.push(']'); break;
                default: if(stk.empty() || stk.top()!=i) 
								return 0;
                            else 
								stk.pop();      
            }
        }
        if(stk.empty()) return 1;
        else return 0;
    }    
};


int main(){
    Solution s = Solution();
    cout << s.isValid("()") <<endl;
    return 0;
}            