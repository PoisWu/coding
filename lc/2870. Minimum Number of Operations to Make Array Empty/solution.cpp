#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &arr)
    {
        map<int, int> freq;
        int res = 0;
        for (auto i : arr) {
            freq[i]++;
        }
        for (auto i : freq) {
            if (i.second == 1)
                return -1;
            else {
                res += i.second / 3 + (i.second % 3 ? 1 : 0);
            }
        }
        return res;
    }
};
