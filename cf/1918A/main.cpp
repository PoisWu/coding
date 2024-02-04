// link: https://codeforces.com/contest/1918/problem/A
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

using namespace std;

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

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        if (m % 2) {
            printf("%d\n", (1 + (m - 3) / 2) * n);
        } else {
            printf("%d\n", m / 2 * n);
        }
    }
}
