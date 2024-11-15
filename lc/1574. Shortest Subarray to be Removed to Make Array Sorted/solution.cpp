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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n-1;
        int ret = n-1;
        while (j-1>=0 && arr[j-1]<= arr[j]){
            j--;
        }
        ret = min(ret, j);
        if (ret == 0) return ret;

        for (int i =0; i<n; i++){
            if (i-1>=0 && arr[i-1]>arr[i]) break;
            while(j< n && arr[i]>arr[j]){
                j++;
            }
            ret = min (ret, j-i-1);
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
