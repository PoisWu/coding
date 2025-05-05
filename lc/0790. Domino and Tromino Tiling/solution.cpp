#include "../include/helper.h"
#include <cmath>

class Solution {
public:
    int mod = pow(10, 9)+7;
    vector<int> ret;

    int numTilings(int n){
        int ret[n+1];
        if (n == 1){
            return 1;
        }

        if (n == 2){
            return  2;
        }

        if (n == 3){
            ret[3] = 1;
            return 5;
        }
        ret[1] = 1;
        ret[2] = 2;
        ret[3] = 5;


        for (int i = 4; i<=n; i++){
            ret[i] = 2*ret[i-1]+ret[i-3];
        }
        return ret[n];

    }


};


int main()
{
    Solution solver;
    cout << solver.numTilings(1) << endl;
    cout << solver.numTilings(2) << endl;
    cout << solver.numTilings(3) << endl;
    cout << solver.numTilings(4) << endl;
    cout << solver.numTilings(5) << endl;

    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    /*cout << solver.<< endl;*/
    return 0;
}

