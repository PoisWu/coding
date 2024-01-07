#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        if (sum <= 50) {
            int exittable[51] = {0};
            for (auto x : nums) {
                exittable[x] = 1;
            }
            while (sum <= 50 && exittable[sum]) {
                sum++;
            }
        }
        return sum;
    }
};
