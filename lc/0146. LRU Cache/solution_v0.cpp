#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <list>
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


class LRUCache
{
public:
    list<int> mylist;
    int cap;
    int size;
    unordered_map<int, list<int>::iterator> key2it;
    unordered_map<int, int> key2val;
    LRUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (key2it.find(key) == key2it.end()) {
            return -1;
        } else {
            mylist.erase(key2it[key]);
            mylist.push_front(key);
            key2it[key] = mylist.begin();
            return key2val[key];
        }
    }

    void put(int key, int value)
    {
        if (get(key) != -1) {
            key2val[key] = value;
            return;
        }

        if (size == cap) {
            int removekey = mylist.back();
            mylist.pop_back();
            key2it.erase(removekey);
            key2val.erase(removekey);
            size--;
        }
        mylist.push_front(key);
        key2it[key] = mylist.begin();
        key2val[key] = value;
        size++;
    }
};

int main()
{
    // Solution solver;
    // vector<int> v1 = {};
    // string s1 = "";
    // string t1 = "";
    // cout << solver.<< endl;
    // print_vector(solver.);
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
