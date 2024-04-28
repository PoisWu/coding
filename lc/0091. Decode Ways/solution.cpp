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

public:
    // recurence
    // X X X X X X
    // return numDecodings(s[pos:])
    int ways(string s)
    {
        if (s.length() == 0)
            return 1;
        if (s[0] == '0')
            return 0;
        if (s.length() == 1)
            return 1;

        if (way.find(s) != way.end()) {
            return way[s];
        }

        int w = ways(s.substr(1, s.length()));

        int num = stoi(s.substr(0, 2));

        if (num <= 26) {
            w += ways(s.substr(2, s.length()));
        }

        way[s] = w;
        return w;
    }
    int numDecodings(string s)
    {
        if (s.length() == 0)
            return 0;
        return ways(s);
    }
    unordered_map<string, int> way;
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "11106";
    string s2 = "12";
    string s3 = "";
    string s4 = "12111211";
    cout << solver.numDecodings(s1) << endl;
    cout << solver.numDecodings(s2) << endl;
    cout << solver.numDecodings(s3) << endl;
    cout << solver.numDecodings(s4) << endl;
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
