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


class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> fifo;
        string rets;
        fifo.push(root);

        while (!fifo.empty()) {
            for (int i = 0; i < fifo.size(); i++) {
                TreeNode *node = fifo.front();
                fifo.pop();
                if (node == NULL) {
                    rets += "#,";
                } else {
                    rets += to_string(node->val) + ",";
                    fifo.push(node->left);
                    fifo.push(node->right);
                }
            }
        }
        return rets;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> v;
        int i = 0;

        while (i < data.length()) {
            if (data[i] != 'N') {
                int len = 0;
                while (data[i + len] != ',') {
                    len++;
                }
                v.push_back(data.substr(i, len));
                i = i + len + 1;
            } else {
                v.push_back("#");
                i = i + 2;
            }
        }

        queue<TreeNode *> fifo;
        if (v.size() == 1) {
            return NULL;
        }


        TreeNode *root = new TreeNode(stoi(v[0]));

        fifo.push(root);
        i = 1;
        while (!fifo.empty()) {
            TreeNode *node = fifo.front();
            fifo.pop();

            if (v[i] == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(v[i]));
                fifo.push(node->left);
            }
            i++;
            if (v[i] == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(v[i]));
                fifo.push(node->right);
            }
            i++;
        }
        return root;
    }
};



int main()
{
    Codec coder;
    vector<int> v1 = {};
    // Following tree
    //              - Null
    //       - 5 - |
    //      |      |      - 9
    //  1 - |       - 4 -|
    //      |             - 2
    //      |       - 10
    //       - 3 - |
    //              - 6
    //
    TreeNode two = TreeNode(2);
    TreeNode nine = TreeNode(9);
    TreeNode four = TreeNode(4, &nine, &two);
    TreeNode five = TreeNode(5, NULL, &four);
    TreeNode ten = TreeNode(10);
    TreeNode six = TreeNode(6);
    TreeNode three = TreeNode(3, &ten, &six);
    TreeNode one = TreeNode(1, &five, &three);
    string s = coder.serialize(&one);
    cout << s << endl;
    TreeNode *dup = coder.deserialize(s);
    string s_dup = coder.serialize(dup);
    cout << s_dup << endl;

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
