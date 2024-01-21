#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

// v1 simple pointer
/* struct ListNode* deleteMiddle(struct ListNode* head){ */
/*     struct ListNode* fast = head; */
/*     struct ListNode* slow = head; */
/*     struct ListNode* pre = NULL; */

/*     while (fast!=NULL && fast->next != NULL){ */
/*         pre = slow; */
/*         fast = (fast->next) -> next; */
/*         slow = slow -> next; */
/*     } */
/*     if (!pre) return NULL; */
/*     else pre->next = slow -> next; */

/*     return head; */
/* } */

// fast!=NULL && fast -> next !=NULL can be writen as
// fast && fast->next
// v2 double pointer
struct ListNode *deleteMiddle(struct ListNode *head)
{
    struct ListNode **inptr = &head;

    for (struct ListNode *fast = head; fast && fast->next;
         fast = fast->next->next) {
        inptr = &(*inptr)->next;
    }
    *inptr = (*inptr)->next;
    return head;
}

int main()
{
    return 0;
}
