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

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 0;
        ListNode *ptr = head;
        while (ptr) {
            length++;
            ptr = ptr->next;
        }

        ListNode **ppnode = &head;

        // head

        for (int i = 0; i < length - n; i++) {
            ppnode = &((*ppnode)->next);
        }

        *ppnode = (*ppnode)->next;
        //
        // if (n == length){
        //     return head -> next;
        // }
        // ptr = head;
        // for (int i = 0; i<length-n-1; i++){
        //     ptr = ptr -> next;
        // }
        // ptr -> next = ptr->next->next;
        return head;
    }
};

void print_listnode(ListNode *head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solver;
    ListNode two = ListNode(2);
    ListNode one = ListNode(1, &two);
    print_listnode(solver.removeNthFromEnd(&one, 1));


    return 1;
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
