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
private:
    static const int mod = 1000000007;
    bool isalphanumeric(char c)
    {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
               ('0' <= c && c <= '9');
    }
    bool cmp(char a, char b)
    {
        if ('0' <= a && a <= '9') {
            return a == b;
        }
        if ('A' <= a && a <= 'Z')
            a = a + 'a' - 'A';
        if ('A' <= b && b <= 'Z')
            b = b + 'a' - 'A';
        return a == b;
    }

public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            // Advance i
            while (i < j && !isalphanumeric(s[i]))
                i++;
            // backward j
            while (i < j && !isalphanumeric(s[j]))
                j--;
            if (!cmp(s[i], s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = "  !@!)(!@       ";
    cout << solver.isPalindrome(s1) << endl;
    cout << solver.isPalindrome(s2) << endl;
    cout << solver.isPalindrome(s3) << endl;
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
