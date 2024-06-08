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
    void reorderList(ListNode *head)
    {
        if (head == NULL) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;
        mid = reverse(mid);
        ListNode *h = head;
        ListNode *h1 = head->next;
        ListNode *h2 = mid;
        while (h1 || h2) {
            if (h2) {
                h->next = h2;
                h2 = h2->next;
                h = h->next;
            }
            if (h1) {
                h->next = h1;
                h1 = h1->next;
                h = h->next;
            }
        }
        h->next = h2;
        return;
    }
    ListNode *reverse(ListNode *head)
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
