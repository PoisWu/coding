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
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
private:
    static const int mod = 1000000007;
    int aux(vector<int>& arr, vector<int>& dp, int idx, int k){
        if(idx==-1){
            return 0;
        }
        if(dp[idx] !=-1){
            return dp[idx];
        }
        int M = -1;
        int Mvalue = 0;
        for (int it = 1; it <= min(idx+1, k); it++){
            M = max(M, arr[idx-it+1]);
            int tmp = it*M + aux(arr, dp, idx-it, k);
            Mvalue = max(Mvalue, tmp);
        }
        dp[idx] = Mvalue;
        return dp[idx];
    }

public:
    int maxSumAfterPartitioning(vector<int> & arr, int k){
        vector<int> dp (arr.size(), -1);
        aux(arr, dp, arr.size()-1, k);
        return dp[arr.size()-1];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1,15,7,9,2,5,10};
    vector<int> v2 = {1,4,1,5,7,3,6,1,9,9,3};
    
    cout << solver.maxSumAfterPartitioning(v1, 3) << endl;
    cout << solver.maxSumAfterPartitioning(v2, 4) << endl;
    return 0;

    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    // TreeNode two = TreeNode(2);
    // TreeNode nine = TreeNode(9);
    // TreeNode four = TreeNode(4, &nine, &two);
    // TreeNode five = TreeNode(5, NULL, &four);
    // TreeNode ten = TreeNode(10);
    // TreeNode six = TreeNode(6);
    // TreeNode three = TreeNode(3, &ten, &six);
    // TreeNode one = TreeNode(1, &five, &three);
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

