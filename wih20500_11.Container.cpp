#include <vector>
#include <iostream>
#include <algorithm>    // std::max
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightlen = height.size();
        int temp = 0;
        int max = 0;
         
        for (int i = 0; i < heightlen; i++){
           for(int j = i + 1; j < heightlen; j++){
               temp = min(height[i],height[j])*abs(i-j);
               if(temp > max){
                 max = temp;
               }
           } 
        } 
        return max;
    }
};


int main(){
    vector<int> height ={1,2,1};
    Solution s = Solution();
    cout<<s.maxArea(height)<<endl;
}