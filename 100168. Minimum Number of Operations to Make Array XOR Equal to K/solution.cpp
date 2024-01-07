# include <iostream>
# include <algorithm>    
# include <vector>
# include <map>


using namespace std;

class Solution{
public: 
    int minOperations(vector<int>& nums, int k) {
        int xorsum=0;
        for (auto x: nums){
            xorsum = xorsum^x;
        }
        // sum with k 
        xorsum ^= k;
        int count = 0;
        while(xorsum!=0){
            xorsum = xorsum&(xorsum-1);
            count++;
        }
        return count;
    }

    
};

