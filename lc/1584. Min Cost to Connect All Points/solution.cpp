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
    int Father[1001];
    int findFather(int x){
        if (x == Father[x]){
            return x;
        }
        return Father[x] = findFather(Father[x]);

    }
    void Union(int x, int y){
        x = Father[x];
        y = Father[y];
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }
    
public:
    int minCostConnectPoints(vector<vector<int>> & points){
        int n = points.size();
        for (int i = 0; i<n; i++){
            Father[i] = i;
        }
        vector<vector<int>>edges; 
        // {dist, i, j}
        for (int i = 0; i< n; i++){
            for (int j = i+1; j <n; j++)
            int dis = abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]);
            edges.push_back({dis, i, j});
        }

        sort(edges.begin(), edges.end());

        int ret = 0;
        int count = 0;
        for (auto edge: edges){
            int dis = edge[0];
            int a = edge[1];
            int b = edge[2];
            if (findFather(a) != findFather(b)){
                ret += dis;
                count ++;
                Union(a, b);
            }
            if (count == n-1){
                break;
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
