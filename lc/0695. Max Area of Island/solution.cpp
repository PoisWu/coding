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

class Solution{
    int ret, n, m;
    vector<vector<int>> dirt = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j){
        if ( i<0 || i>=n || j<0 || j>=m || grid[i][j] !=1){
            return 0;
        }
        grid[i][j] = 0;
        int ret = 1;
        for (int idx = 0; idx<4; idx++){
            ret += dfs(grid, i+dirt[idx][0], j+dirt[idx][1]);
        }
        return ret;
    }
public: 
    int maxAreaOfIsland(vector<vector<int>> & grid){
        ret = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i <n ; i++){
            for (int j = 0; j<m; j++){
                ret = max(ret, dfs(grid, i, j));
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
