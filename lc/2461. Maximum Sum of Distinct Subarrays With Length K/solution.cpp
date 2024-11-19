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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int nb_double = 0;
        int n = nums.size();
        long long ret = 0;
        long long tmp = 0;
        int end = k-1;
        //init phase
        for (int j = 0; j<k; j++){
            tmp = tmp + nums[j];
            freq[nums[j]]++;
            if (freq[nums[j]]==2){
                nb_double ++;
            }
        }

        if (nb_double==0){
            ret = max(ret, tmp);
        }

        for (end=k; end<n ; end++){
            tmp = tmp+nums[end];
            freq[nums[end]]++;
            if (freq[nums[end]]==2){
                nb_double ++;
            }
            tmp = tmp - nums[end-k];
            freq[nums[end-k]]--;
            if (freq[nums[end-k]]==1){
                nb_double --;
            }
            if (nb_double==0){
                ret = max(ret, tmp);
            }
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1,5,4,2,9,9,9};
    vector<int> v2 = {4,4,4};

    string s1 = "";
    string t1 = "";
    cout << solver.maximumSubarraySum(v2,3) << endl;
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
