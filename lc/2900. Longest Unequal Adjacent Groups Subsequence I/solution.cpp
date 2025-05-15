#include "../include/helper.h"

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // [start, end[
        int n = groups.size();
        vector<string> ret;
        ret.push_back(words[0]);
        
        int end = 1;
        while (end < n){
            if (groups[end-1] != groups[end]){
                ret.push_back(words[end]);
            }
            end++;
        }
        return ret; 
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1,0,1,1};
    vector<string> s1 = {"a","b","c","d"};
    /*cout << solver.<< endl;*/
    print_vector(solver.getLongestSubsequence(s1, v1));
    return 0;
}

