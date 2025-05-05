#include "../include/helper.h"

class Solution{
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> table(10, vector<int>(10, 0));
        for (int i =0 ; i<dominoes.size(); i++){
            int x, y = dominoes[i][0], dominoes[i][1];
            if (x>y) swap(x, y);
            table[x][y]++;

        }
        int ret = 0;
        for (int i= 0; i<10; i++){
            for (int j = 0; j<=i; j++){
                int tmp = table[i][j];
                ret += tmp*(tmp+1)/2;
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
    return 0;
}

