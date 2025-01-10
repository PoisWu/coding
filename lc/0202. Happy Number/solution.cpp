#include "../include/helper.h"

class Solution{
public: 
    bool isHappy(int n){
        unordered_set<int> set; 
        while (set.count(n) == 0){
            set.insert(n);
            int nxt = 0; 
            while (n !=0){
                int tmp = n%10;
                nxt+= tmp*tmp;
                n = n/10;
            }
            if (nxt == 1){
                return true;
            }
            n = nxt;
        }
        return false;


    }
};


int main()
{
    Solution solver;

    cout << solver.isHappy(19)<< endl;
    cout << solver.isHappy(2)<< endl;
    return 0;
}

