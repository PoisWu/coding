/**
 * Creater: Nonamefour
 * Creat data:2021-06-28
 * Purpose:leet 19.Remove Nth Node From End of List
 *
 * End data:
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<int> vec = vector<int>();
        for (ListNode *s = head; !s->next; s = s->next) {
            vec.push_back(s->val);
            reverse(vec.begin(), vec.end());
        }
        ListNode *res = NULL;
        ListNode aux;
        for (int i = 1; i <= vec.size(); i++) {
            if (i != n) {
                aux = ListNode(vec[i - 1], res);
                res = &aux;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
