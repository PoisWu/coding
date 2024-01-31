#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
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


class Solution
{
private:
    void build_graph(TreeNode *root, unordered_map<int, vector<int>> &graph)
    {
        vector<TreeNode *> hp;
        hp.push_back(root);
        while (!hp.empty()) {
            TreeNode *node = hp.back();
            hp.pop_back();
            int val = node->val;
            if (node->left) {
                int val_left = node->left->val;
                graph[val].push_back(val_left);
                graph[val_left].push_back(val);
                hp.push_back(node->left);
            }
            if (node->right) {
                int val_right = node->right->val;
                graph[val].push_back(val_right);
                graph[val_right].push_back(val);
                hp.push_back(node->right);
            }
        }
    };

public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> graph;
        // convert tree to graph
        build_graph(root, graph);
        // for(const auto& [val, list_adj_v]: graph){
        //     cout << val << " ";
        //     print_vector(list_adj_v);
        // }
        // Run a bfs to compute the
        unordered_set<int> isvisited;
        queue<int> fifo;
        fifo.push(start);
        int res = -1;

        while (!fifo.empty()) {
            // cout << "-----------" << endl;
            res++;
            int nb_same_rank = fifo.size();
            for (int i = 0; i < nb_same_rank; i++) {
                int val = fifo.front();
                fifo.pop();
                isvisited.insert(val);
                cout << val << " ";
                for (auto adj : graph[val]) {
                    if (!isvisited.count(adj)) {
                        fifo.push(adj);
                    }
                }
            }
            // cout << "res " << res << endl;
            // cout << endl;
        }
        return res;
    }
};

int main()
{
    Solution solver;
    TreeNode two = TreeNode(2);
    TreeNode nine = TreeNode(9);
    TreeNode four = TreeNode(4, &nine, &two);
    TreeNode five = TreeNode(5, NULL, &four);
    TreeNode ten = TreeNode(10);
    TreeNode six = TreeNode(6);
    TreeNode three = TreeNode(3, &ten, &six);
    TreeNode one = TreeNode(1, &five, &three);

    cout << solver.amountOfTime(&one, 3) << endl;

    // vector < ? ? > v1 = {};
}
