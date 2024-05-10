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

class Solution
{
    ListNode *helper(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == NULL || l2 == NULL) {
            if (l1 == NULL && l2 == NULL) {
                return carry ? new ListNode(1) : NULL;
            }

            if (l1 == NULL) {
                swap(l1, l2);
            }
            int v = l1->val + carry;
            carry = v / 10;
            l1->val = v % 10;
            l1->next = helper(l1->next, l2, carry);
            return l1;
        }
        int v = l1->val + l2->val + carry;
        ListNode *node = new ListNode(v % 10);
        node->next = helper(l1->next, l2->next, v / 10);
        return node;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
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
