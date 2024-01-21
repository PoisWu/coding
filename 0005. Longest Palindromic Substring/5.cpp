#include <algorithm>  // std::max
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int strlen = s.length();
        int start = 0;
        int length_substring = 1;
        for (int center = 0; center < strlen; center++) {
            // even
            if (center + 1 < strlen && s[center + 1] == s[center]) {
                int i = 1;
                while (center - i >= 0 && center + 1 + i < strlen) {
                    if (s[center - i] != s[center + 1 + i]) {
                        break;
                    }
                    i++;
                }
                i--;
                if (2 + 2 * i > length_substring) {
                    length_substring = 2 + 2 * i;
                    start = center - i;
                }
            }
            // odd
            int i = 1;
            while (center - i >= 0 && center + i < strlen) {
                if (s[center - i] != s[center + i]) {
                    break;
                }
                i++;
            }
            i--;
            if (1 + 2 * i > length_substring) {
                length_substring = 1 + 2 * i;
                start = center - i;
            }
        }
        return s.substr(start, length_substring);
    }
};


int main()
{
    std::string test = "babad";
    Solution s = Solution();
    std::cout << s.longestPalindrome(test) << std::endl;
}