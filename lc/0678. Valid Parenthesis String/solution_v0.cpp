#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
using lli = long long int;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);


class Solution
{
public:
    bool checkValidString(string s)
    {
        int countMax = 0;
        int countMin = 0;
        for (char ch : s) {
            if (ch == '(') {
                countMax++;
                countMin++;
            } else if (ch == ')') {
                countMax--;
                countMin--;
            } else {
                countMax++;
                countMin--;
            }
            if (countMax < 0) {
                return false;
            }

            if (countMin < 0) {
                countMin = 0;
            }
        }
        return countMin == 0;
    }
};

// too slow
// class Solution {
// public:
//     int cnt;
//     bool checkValidString(string s) {
//         cnt = 0;
//         return dfs(s, 0);
//     }
//     bool dfs(string s, int i){
//         if (i == s.length()){
//             return cnt==0;
//         }
//         if (s[i] == ')'){
//             if (cnt == 0){
//                 return false;
//             }
//             cnt --;
//             bool result = dfs(s, i+1);
//             cnt++;
//             return result;
//         }else if (s[i] == '('){
//             cnt ++;
//             bool result = dfs(s, i+1);
//             cnt --;
//             return result;
//         }else if (s[i] == '*'){
//             if (dfs(s, i+1)){
//                 return true;
//             }
//
//             bool possible1;
//             if (cnt != 0){
//                 cnt--;
//                 possible1 = dfs(s, i+1);
//                 cnt++;
//             }
//             if (possible1){
//                 return true;
//             }
//
//             cnt ++;
//             bool ret = dfs(s, i+1);
//             cnt --;
//             return ret;
//         }
//         return false;
//     }
// };

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "(*))";
    string s2 = "()";
    string s3 = "(*)";
    cout << solver.checkValidString(s1) << endl;
    cout << solver.checkValidString(s2) << endl;
    cout << solver.checkValidString(s3) << endl;
    return 0;
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

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
