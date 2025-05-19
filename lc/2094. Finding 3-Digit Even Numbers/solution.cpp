#include "../include/helper.h"

class Solution{
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int arr[1000];
        for (int i=0; i<1000;i++){
            arr[i] = 0;
        }
        vector<int> ret;
        for (int i = 0; i<digits.size(); i++){
            for (int j = 0; j<digits.size(); j++){
                for (int k =0; k<digits.size(); k++){
                    if (i==j || j ==k || i ==k){
                        continue;
                    }
                    if (digits[k]%2 != 0 || digits[i] == 0){
                        continue;
                    }
                    int tmp = 100*digits[i]+10*digits[j]+digits[k];
                    if (arr[tmp] == 1){
                        continue;
                    }
                    ret.push_back(tmp);
                    arr[tmp] = 1;
                }

            }
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {2,1,3,0};
    print_vector(solver.findEvenNumbers(v1));
    return 0;
}

