/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:leet 28.Implement strStr()
 *
 * End data:07-04
 * Runtime:100%
 * Memory Usage:74.45%
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (!needle.length())
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j])
                    break;
                if (j == needle.size() - 1)
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s = Solution();
    return 0;
}
