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

class Solution {
public:
    bool isPrefix(string& w1, string &w2){
        if (w1.length()>w2.length()){
            return false;
        }
        for (int i =0; i<w1.length(); i++){
            if (w1[i]!=w2[i]){
                return false;
            }
        }
        return true;
    }
    bool isSuffix(string& w1, string &w2){
        if (w1.length()>w2.length()){
            return false;
        }
        for (int i =0; i<w1.length(); i++){
            if (w1[i]!=w2[w2.length()-w1.length()+i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ret = 0;
        for(int i = 0; i<n; i++){
            for (int j = i+1; j<n; j++){
                string w1 = words[i];
                string w2 = words[j];
                if (isPrefix(w1, w2) && isSuffix(w1, w2)){
                    ret ++;
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.<< endl;
    print_vector(solver.);
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
