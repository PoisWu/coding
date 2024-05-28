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

class DetectSquares
{
    unordered_map<int, unordered_map<int, int>> map;

public:
    DetectSquares() {}

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        map[x][y]++;
    }

    int count(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        unordered_map<int, int> vector_y = map[x];
        int ret = 0;
        for (auto m : vector_y) {
            int y0 = m.first;
            int n0 = m.second;
            int d = y0 - y;
            if (d == 0) {
                continue;
            }
            // search (x+d, y0)
            // (x+d, y)
            int n1 = map[x + d][y0];
            int n2 = map[x + d][y];
            ret += n0 * n1 * n2;


            // (x-d, y0)
            // (x-d, y)
            n1 = map[x - d][y0];
            n2 = map[x - d][y];
            ret += n0 * n1 * n2;
        }
        return ret;
    }
};


int main()
{
    DetectSquares *d = new DetectSquares();
    d->add({3, 10});
    d->add({11, 2});
    d->add({3, 2});
    cout << d->count({11, 10}) << endl;
    cout << d->count({14, 8}) << endl;
    d->add({11, 2});
    cout << d->count({11, 10}) << endl;

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
