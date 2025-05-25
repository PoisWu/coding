#include "../include/helper.h"

class Solution {
public:
    int convertToInt(string s){
        int ret = 0;
        for (auto c: s){
            ret = ret*26 + (c-'a');
        }
        return ret;
    }
    int invert(int n){
        int a = n%26;
        int b = n/26;
        return a*26+b;
    }
    int longestPalindrome(vector<string>& words) {
        // 26*26 = 676
        int freq[676] = {0};
        for (auto s: words){
            freq[convertToInt(s)]++;
        }

        bool takeOdd = false;
        int cnt = 0;

        for (int i = 0; i<676; i++){
            if (invert(i) == i){
                cnt+= freq[i] - (freq[i]%2);
                if (!takeOdd && freq[i]%2){
                    cnt+=1;
                    takeOdd = true;
                }

            }else{
                cnt+= min(freq[i], freq[invert(i)]);
            }
        }
        return cnt*2;
        
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"lc", "cl", "gg"};
    vector<string> v2 = {"ab","ty","yt","lc","cl","ab"};
    vector<string> v3 = {"cc","ll","xx"};
    cout << solver.longestPalindrome(v1) << endl;
    cout << solver.longestPalindrome(v2) << endl;
    cout << solver.longestPalindrome(v3) << endl;
    return 0;
}

