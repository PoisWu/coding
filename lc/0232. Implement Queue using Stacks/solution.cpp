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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

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


class MyQueue
{
private:
    stack<int> one;
    stack<int> two;

public:
    MyQueue() {}

    void push(int x) { one.push(x); }

    int pop()
    {
        int n;
        if (two.empty()) {
            while (!one.empty()) {
                int tmp = one.top();
                two.push(tmp);
                one.pop();
            }
        }
        n = two.top();
        two.pop();
        return n;
    }

    int peek()
    {
        int n;
        if (two.empty()) {
            while (!one.empty()) {
                int tmp = one.top();
                two.push(tmp);
                one.pop();
            }
        }
        n = two.top();
        return n;
    }

    bool empty() { return two.empty() && one.empty(); }
};

int main()
{
    MyQueue a = MyQueue();
    a.push(1);
    cout << a.pop() << endl;
}
