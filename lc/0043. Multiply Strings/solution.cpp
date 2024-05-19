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
    string multiply(string num1, string num2)
    {
        int m = num1.length();
        int n = num2.length();
        vector<int> result(m + n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // compute nums[m-1-i]*nums[n-1-j]
                int a = num1[m - 1 - i] - '0';
                int b = num2[n - 1 - j] - '0';
                int prod = a * b + result[i + j];
                result[i + j + 1] += prod / 10;
                result[i + j] = prod % 10;
            }
        }
        string ret = "";
        bool isSeen = false;
        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == 0 && !isSeen)
                continue;
            ret.push_back('0' + result[i]);
            isSeen = true;
        }
        return ret != "" ? ret : "0";
    }
};

int main()
{
    Solution solver;
    string s1 = "12";
    string t1 = "3";
    cout << solver.multiply(s1, t1) << endl;
    cout << solver.multiply("0", "100") << endl;
    cout << solver.multiply("42", "105") << endl;
    cout << solver.multiply("123", "456") << endl;
    return 1;
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
