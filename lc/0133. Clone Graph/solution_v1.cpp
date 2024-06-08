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

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *root)
    {
        if (root == NULL) {
            return NULL;
        }
        unordered_set<Node *> set;
        unordered_map<Node *, Node *> map;

        // creating new nodes;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (map.find(node) != map.end()) {
                continue;
            }
            map[node] = new Node(node->val);
            for (auto nei : node->neighbors) {
                if (map.find(nei) == map.end())
                    q.push(nei);
            }
        }
        // build the links
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (set.find(node) != set.end()) {
                continue;
            }
            set.insert(node);
            for (auto nei : node->neighbors) {
                map[node]->neighbors.push_back(map[nei]);
                if (set.find(nei) == set.end())
                    q.push(nei);
            }
        }

        return map[root];
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    cout << solver.<< endl;
    print_vector(solver.);
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
