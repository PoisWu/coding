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
void print_vector(vector<T> vec);
template <typename T>
void print_2d_vector(vector<vector<T> > vvec);

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        long long a, b, r;
        cin >> a >> b >> r;
        int start = 0;
        // a >= b
        if (a < b)
            swap(a, b);
        long long cur = 0;
        for (int i = 60; i >= 0; i--) {
            int x = a >> i & 1;
            int y = b >> i & 1;
            if (x == y)
                continue;
            if (x > y) {
                if (!start)
                    start = 1;
                else if ((cur | (1LL << i)) <= r) {
                    cur = (cur | (1LL << i));
                }
            }
        }
        cout << abs((a ^ cur) - (b ^ cur)) << endl;
    }
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

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}
