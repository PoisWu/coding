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
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        queue<vector<int>> q;

        q.push({nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            int nb_ele = q.size();
            while (nb_ele--) {
                vector<int> arr = q.front();
                q.pop();

                for (int j = 0; j <= arr.size(); j++) {
                    vector<int> tmp = arr;
                    tmp.insert(tmp.begin() + j, nums[i]);
                    q.push(tmp);
                }
            }
        }
        vector<vector<int>> ret;
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {1, 2, 3};
    string s1 = "";
    string t1 = "";
    print_2d_vector(solver.permute(v1));
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
