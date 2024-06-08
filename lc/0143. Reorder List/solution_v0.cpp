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
private:
    static const int mod = 1000000007;

    ListNode *reverse(ListNode *head)
    {
        ListNode *last = NULL;
        ListNode *cur = head;
        ListNode *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }
        return last;
    }

public:
    void reorderList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p = dummy;
        int count = 0;
        while (p->next) {
            count++;
            p = p->next;
        }

        ListNode *cut = dummy;
        for (int i = 0; i < (count + 1) / 2; i++) {
            cut = cut->next;
        }
        ListNode *head2 = cut->next;
        cut->next = NULL;
        head2 = reverse(head2);


        ListNode *h = dummy;
        ListNode *h1 = head;
        ListNode *h2 = head2;
        while (h1 || h2) {
            if (h1) {
                h->next = h1;
                h1 = h1->next;
                h = h->next;
            }
            if (h2) {
                h->next = h2;
                h2 = h2->next;
                h = h->next;
            }
        }
        // return head;
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
