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

class MedianFinder
{
    multiset<int> set;
    multiset<int>::iterator iter;
    double result;

public:
    MedianFinder()
    {
        set.clear();
        result = 0;
    }

    void addNum(int num)
    {
        set.insert(num);

        if (set.size() % 2 == 1) {
            // 0x00 -> 0x000
            if (num >= *iter) {
                iter = next(iter, 1);
            }
            result = *iter;

        } else {
            // 00x00 -> 000x00
            if (num < *iter) {
                iter = prev(iter, 1);
            }
            result = *iter * 0.5 + *next(iter, 1) * 0.5;
        }
    }

    double findMedian() { return result; }
};


int main()
{
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
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
