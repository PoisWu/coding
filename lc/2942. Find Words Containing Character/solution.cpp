#include "../include/helper.h"

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        for (int i = 0; i<words.size(); i++){
            for (int j = 0; j<words[i].length(); j++){
                if (words[i][j] == x){
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    /*cout << solver.<< endl;*/
    print_vector(v1);
    return 0;
}

