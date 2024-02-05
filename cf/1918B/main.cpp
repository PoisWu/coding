// link: https://codeforces.com/contest/1918/problem/B
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
void print_2d_vector(vector<vector<T>> vvec)
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
//
// 1 2 3 4 5
// 5 4 3 2 1 (4+3+2+1 = 10

// 3 2 5 1 4 (2+1+2 = 5
// 3 4 1 5 2 (2+2+1 = 5


int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        // scanf
        int n;
        scanf("%d\n", &n);
        int a[n];
        int b[n];
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", a + i);
        }
        scanf("%d\n", a + n - 1);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", b + i);
        }
        scanf("%d\n", b + n - 1);

        vector<pair<int, int>> validx;
        for (int i = 0; i < n; i++) {
            validx.push_back(make_pair(a[i], i));
        }
        sort(validx.begin(), validx.end());


        for (int i = 0; i < n - 1; i++) {
            printf("%d ", validx[i].first);
        }
        printf("%d\n", validx[n - 1].first);

        for (int i = 0; i < n - 1; i++) {
            printf("%d ", b[validx[i].second]);
        }
        printf("%d\n", b[validx[n - 1].second]);
    }
}
