#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;

public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length()) {
            return "";
        }
        int start = 0;
        int _start;
        int minWindow = s.length() + 1;
        unordered_map<char, int> freq;
        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]++;
        }
        for (int end = 0; end < s.length(); end++) {
            char c = s[end];
            if (freq.find(c) != freq.end()) {
                freq[c]--;
                // advance start;
                bool isempty = true;
                for (auto &x : freq) {
                    if (x.second > 0) {
                        isempty = false;
                        break;
                    }
                }
                while (isempty) {
                    if (minWindow > (end - start + 1)) {
                        minWindow = end - start + 1;
                        _start = start;
                    }
                    char cs = s[start];
                    if (freq.find(cs) != freq.end()) {
                        freq[cs]++;
                        if (freq[cs] > 0) {
                            isempty = false;
                        }
                    }
                    start++;
                }
            }
        }
        if (minWindow < s.length() + 1) {
            return s.substr(_start, minWindow);
        } else {
            return "";
        }
    }
};

int main()
{
    Solution solver;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    string s3 = "aa";
    string t3 = "aa";
    cout << solver.minWindow(s3, t3) << endl;
    cout << solver.minWindow(s1, t1) << endl;
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
