// Attempt but time out @@
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
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
private:
    static const int mod = 1000000007;
    vector<int> parent;
    unordered_set<int> primes;

    int f(int i)
    {
        assert(i < parent.size() && i >= 0);
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    };
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    void u(int a, int b)
    {
        assert(a < parent.size() && a >= 0);
        assert(b < parent.size() && b >= 0);
        int ra = f(a);
        int rb = f(b);
        if (ra == rb)
            return;
        if (ra < rb) {
            parent[rb] = ra;
        } else {
            parent[ra] = rb;
        }
    }

    void build_prime(int n)
    {
        primes.clear();
        vector<bool> table(n + 1, true);
        for (int i = 2; i < n + 1; i++) {
            if (table[i]) {
                primes.insert(i);
                for (int j = 1; j * i < n + 1; j++) {
                    table[i * j] = false;
                }
            }
        }
    }


public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        build_prime(n);
        unordered_map<int, vector<int>> prime_list;
        for (int i = 0; i < n; i++) {
            for (auto p : primes) {
                if (nums[i] % p == 0) {
                    prime_list[p].push_back(i);
                }
            }
        }

        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto it : prime_list) {
            for (int i = 0; i < it.second.size() - 1; i++) {
                u(it.second[i], it.second[i + 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (f(i) != 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solver;
    vector<int> v2 = {33, 60};
    string s1 = "";
    string t1 = "";
    // cout << solver.canTraverseAllPairs(v1)<< endl;
    cout << solver.canTraverseAllPairs(v2) << endl;
    // cout << solver.canTraverseAllPairs(v3)<< endl;
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
