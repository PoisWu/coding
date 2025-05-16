#include "../include/helper.h"

class Solution {
public:

    bool isOk(string s1, string s2){
        if (s1.length() != s2.length()){
            return false;
        }
        int diff = 0;
        for (int i = 0; i<s1.length(); i++){
            if (s1[i]!=s2[i]){
                diff++;
            }
            if (diff>=2 ){
                return false;
            }
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        // (length, prev idx)
        vector<pair<int, int>> dp(n, make_pair(0,-1));
        int gmaxLen = 1;
        int gIdx = 0;

        for (int i = 0; i<n; i++){
            int localmaxLen = 1;
            int localpre = -1;
            for (int j = 0 ; j<i; j++){
                if (groups[j]!= groups[i] && isOk(words[j], words[i])){
                    int len = dp[j].first;
                    if (len+1 > localmaxLen){
                        localmaxLen = len+1;
                        localpre = j;
                    }
                }
            }
            dp[i] = make_pair(localmaxLen, localpre);
            if (localmaxLen>gmaxLen){
                gmaxLen = localmaxLen;
                gIdx = i;
            }
        }

        stack<int> heap;

        while(gIdx!= -1){
            heap.push(gIdx);
            gIdx = dp[gIdx].second;
        }

        vector<string> ret;

        while (!heap.empty()){
            ret.push_back(words[heap.top()]);
            heap.pop();
        }

        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {1,2,2};
    vector<string> s1 = {"bab","dab","cab"};
    vector<int> v2 = {1,2,3, 4};
    vector<string> s2 = {"a","b","c", "d"};
    /*cout << solver.<< endl;*/
    print_vector(solver.getWordsInLongestSubsequence(s1, v1));
    print_vector(solver.getWordsInLongestSubsequence(s2, v2));
    return 0;
}


// dp[n]: (Longest subsequence end at word dp[n], prev location)
//
