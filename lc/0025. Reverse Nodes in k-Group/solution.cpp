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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<ListNode *> heads;
        ListNode *node = head;
        int flag = 0;
        while (node) {
            heads.push_back(node);
            for (int i = 0; i < k - 1; i++) {
                if (node->next) {
                    node = node->next;
                } else {
                    flag = 1;
                }
            }
            ListNode *tmp = node->next;
            node->next = NULL;
            node = tmp;
        }

        for (int i = 0; i < heads.size(); i++) {
            if (flag && i == heads.size() - 1)
                continue;
            heads[i] = rev(heads[i]);
        }

        for (int i = 0; i < heads.size() - 1; i++) {
            node = heads[i];
            while (node->next) {
                node = node->next;
            }
            node->next = heads[i + 1];
        }
        return heads[0];
    }
    ListNode *rev(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main()
{
    Solution solver;
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
