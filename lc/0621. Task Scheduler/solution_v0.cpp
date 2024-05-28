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
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        int nb_task = tasks.size();
        for (auto c : tasks) {
            freq[c]++;
        }
        int max_freq = INT_MIN;
        int nb_max = 0;
        for (auto m : freq) {
            if (max_freq < m.second) {
                max_freq = m.second;
                nb_max = 1;
            } else if (max_freq == m.second) {
                nb_max++;
            }
        }
        n++;
        if (n * (max_freq - 1) + nb_max < nb_task) {
            return nb_task;
        }
        return n * (max_freq - 1) + nb_max;
    }
};


int main()
{
    Solution solver;
    vector<char> v1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> v2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    vector<char> v3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    string s1 = "";
    string t1 = "";
    cout << solver.leastInterval(v1, 2) << endl;
    cout << solver.leastInterval(v2, 1) << endl;
    cout << solver.leastInterval(v3, 3) << endl;
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
