/**
 * Creater: Nonamefour
 * Creat data:2021-07-02
 * Purpose:leet 24.Swap Nodes in Pairs
 *
 * End data:07-02
 * Runtime:
 *      4ms
 *      61.78%
 * Memory Usage:
 *      7.6 MB
 *      49.13%
 */

#include<iostream> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* swapPairs(ListNode* head){
            ListNode dummy = ListNode();
            dummy.next = head;
            ListNode *walker = &dummy;
            while(walker->next != NULL && walker->next->next != NULL){
                ListNode * child = walker->next;
                ListNode * grand_child = walker->next->next;
                walker->next = grand_child;
                child->next = grand_child->next;
                grand_child->next=child;
                walker = walker->next->next;
            }
            return dummy.next;
        }
};

int main(){
    
    return 0;
}
