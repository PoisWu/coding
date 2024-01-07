#include <algorithm>  // std::max
#include <iostream>
#include <map>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int length_string = s.length();
        if (length_string == 0 || length_string == 1) {
            return length_string;
        }
        int start = 0;
        int end = 1;
        int max_length = 0;
        std::map<char, int> dict;
        dict[s[0]] = 0;
        while (end < length_string) {
            if (dict.count(s[end])) {
                if (dict[s[end]] < start) {
                    dict[s[end]] = end;
                } else {
                    max_length = std::max(max_length, end - start);
                    start = dict[s[end]] + 1;
                    dict[s[end]] = end;
                }
            } else {
                dict[s[end]] = end;
            }
            // std::cout <<"max length "<< max_length <<std::endl;
            // std::cout << dict['b']<<std::endl;
            end++;
        }
        // std::cout << "start " <<start << " end " << end <<std::endl;

        max_length = std::max(max_length, end - start);
        return max_length;
    }
};

int main()
{
    std::string test = "abcabcbb";
    Solution s = Solution();
    std::cout << s.lengthOfLongestSubstring(test) << std::endl;
}