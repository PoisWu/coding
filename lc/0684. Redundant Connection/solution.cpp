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
    int Father[1001];
    int findFather(int x){
        if (Father[x] == x){
            return x;
        }
        return Father[x] = findFather(Father[x]);
    }

    void Union(int a, int b){
        a = findFather(a);
        b = findFather(b);
        if (a < b){
            Father[a] = b;
        }else{
            Father[b] = a;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        for (int i = 0; i<n; i++){
            Father[i] = i;
        }
        for (auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            if (findFather(a)== findFather(b)){
                return {a,b};
            }
            Union(a,b);
        }
        return {0,0};
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
