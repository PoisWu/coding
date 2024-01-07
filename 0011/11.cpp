#include <algorithm>  //min
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int end = height.size() - 1;
        int start = 0;
        int max_area = 0;
        while (start < end) {
            if (height[start] < height[end]) {
                if (height[start] * (end - start) > max_area) {
                    max_area = height[start] * (end - start);
                }
                start++;
            } else {
                if (height[end] * (end - start) > max_area) {
                    max_area = height[end] * (end - start);
                }
                end--;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(8);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(5);
    vect.push_back(4);
    vect.push_back(8);
    vect.push_back(3);
    vect.push_back(7);

    cout << s.maxArea(vect);
}
