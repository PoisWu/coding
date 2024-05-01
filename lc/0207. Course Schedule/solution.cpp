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
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
    vector<int> isVisited;
    vector<vector<int>> next;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        isVisited.resize(numCourses, 0);
        next.resize(numCourses);
        // [p0, p1] p0 -> p1   p1 first

        for (auto p : prerequisites) {
            next[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i) == true)
                return false;
        }
        return true;
    }


    bool hasCycle(int i)
    {
        if (isVisited[i] == 1)
            return false;
        if (isVisited[i] == 2)
            return true;

        isVisited[i] = 2;
        for (auto x : next[i]) {
            if (hasCycle(x))
                return true;
        }
        isVisited[i] = 1;
        return false;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1, 0});
    // v1.push_back({1,0});
    string s1 = "";
    string t1 = "";
    cout << solver.canFinish(2, v1) << endl;
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
