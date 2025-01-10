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
    void countFreq(int (&freq)[26], string s){
        for (int i =0; i<s.length(); i++){
            freq[s[i]-'a'] ++;
        }
    }
    bool checkOk(int (&tmp)[26], int (&freq)[26]){
        for (int i = 0; i<26; i++){
            if (tmp[i]<freq[i]){
                return false;
            }
        }
        return true;
    }
    void init(int (&tmp)[26]){
        for (int i=0; i<26; i++){
            tmp[i] = 0;
        }
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26];
        init(freq);

        for (string s: words2){
            int tmp[26];
            init(tmp);
            
            countFreq(tmp, s);
            for (int i = 0; i<26; i++){
                freq[i] = max(freq[i], tmp[i]);
            }
        }
        vector<string> ret;
        for (string s: words1){
            int tmp[26];
            init(tmp);
            countFreq(tmp, s);
            if (checkOk(tmp, freq)){
                ret.push_back(s);
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<string> v1 = {"amazon","apple","facebook","google","leetcode"}; 
    vector<string> v2 = {"e","o"};

    print_vector(solver.wordSubsets(v1, v2));
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
