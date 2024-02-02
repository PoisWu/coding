#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";

    }
    cout << endl;
}

// some cool Idea: The sequentialDigits is substring of 123456789 with variable
// length and started position.
// class Solution {
// public:
//     string s = "123456789";
//     
//     vector<int> sequentialDigits(int L, int R) {
//         vector<int> ans;
//         for (int len = 1; len <= 9; len++) {
//             for (int i = 0; i + len <= 9; i++) {
//                 int x = stoi(s.substr(i, len));
//                 if (L <= x && x <= R) {
//                     ans.push_back(x);
//                 }
//                 if (x > R) break;
//             }    
//         }
//         return ans;
//     }
// };

class Solution
{
private:
    static const int mod = 1000000007;

public:
    vector<int> sequentialDigits(int low, int high){
        // go through the leading digit from 1 to 9
        vector<int> res; 
        for(int i = 1; i<10;i++){
            int nxt_digit = i+1;
            int cur = i;
            while(cur <= high && nxt_digit <= 10){
                if (low <= cur){
                    res.push_back(cur);
                }
                cur = cur * 10 + nxt_digit; 
                nxt_digit++; 
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution solver;
    print_vector(solver.sequentialDigits(100,300));
    print_vector(solver.sequentialDigits(1000,13000));
}
