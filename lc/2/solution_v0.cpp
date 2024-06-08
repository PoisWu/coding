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
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        vector<int> next_big(n, n);
        vector<bool> biggerthanpre(n, false);
        stack<int> q;
        int max_idx = 0;
        int max_val = -1;
        for (int i = 0; i < n; i++) {
            if (max_val < skills[i]) {
                max_idx = i;
                max_val = skills[i];
                biggerthanpre[i] = true;
            }
            if (q.empty()) {
                q.push(i);
            } else {
                if (skills[q.top()] > skills[i]) {
                    q.push(i);
                } else {
                    while (!q.empty() && skills[q.top()] < skills[i]) {
                        next_big[q.top()] = i;
                        q.pop();
                    }
                    q.push(i);
                }
            }
        }
        if (k >= n - 1) {
            return max_idx;
        }
        if (next_big[0] - 0 - 1 >= k) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            if (biggerthanpre[i] && next_big[i] - i - 1 >= k - 1) {
                return i;
            }
        }
        return max_idx;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {4, 2, 6, 3, 9};
    cout << solver.findWinningPlayer(v1, 2) << endl;
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
