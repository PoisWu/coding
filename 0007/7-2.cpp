/**
 * Creater: Nonamefour
 * Creat data:2021-07-02
 * Purpose:Leet Monthly challenge(July) 07-02 Find K Closest Elements
 *
 * End data:07-02
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int left, right;
        if (x < arr[0]) {
            left = 0;
            right = k - 1;
        } else if (x > arr[arr.size() - 1]) {
            right = arr.size() - 1;
            left = arr.size() - k;
        } else {
            left = 0;
            while (x > arr[left])
                left++;
            // cout << "Test: " << "left" <<left <<endl;
            if (x == arr[left])
                right = left;
            else {
                if (arr[left] - x >= x - arr[left - 1]) {
                    left--;
                    right = left;
                } else {
                    right = left;
                }
            }
            while (right - left + 1 < k) {
                if (left == 0)
                    right++;
                else if (right == arr.size() - 1)
                    left--;
                else {
                    if (arr[right + 1] - x < x - arr[left - 1])
                        right++;
                    else
                        left--;
                }
                // cout << "Test: " << left << " " << right  <<endl;
            }
        }
        vector<int> result = vector<int>();
        for (int i = 0; i < k; i++) {
            result.push_back(arr[left + i]);
        }
        return result;
    }
};


int main()
{
    Solution s = Solution();
    vector<int> vec = vector<int>();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vector<int> out_put = s.findClosestElements(vec, 4, 3);
    // cout << "hi" << endl;
    for (int i = 0; i < out_put.size(); i++)
        cout << out_put[i] << endl;
    return 0;
}
