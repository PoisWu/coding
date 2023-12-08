# include <stddef.h>
# include <stdio.h>
#include <stdint.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
/* struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){ */

/*     /1* struct ListNode* head = (list1->value < list2->value) ? list1 : list2 ; *1/ */
/*     struct ListNode* head; */
/*     struct ListNode* ptr; */
/*     struct ListNode* node; */
/*     int isFirst = 1; */
    
/*     // problem: didn't update list1, list2 */
/*     for (; node = (list1->val < list2->val) ? list1: list2 ; list1 || list2){ */
/*         if (isFirst){ */
/*             head = node; */
/*             ptr = node; */
/*             isFirst =0; */
/*         }else{ */
/*             ptr -> next = node; */
/*             ptr = ptr-> next; */
/*         } */
/*         node = node -> next; */ 
/*     } */
/*     if (!list1) ptr -> next = list2; */
/*     if (!list2) ptr -> next = list1; */

/*     return head; */
/* } */

/* struct ListNode* mergeTwoLists(struct ListNode * list1, struct ListNode * list2){ */
/*     struct ListNode* head; */
/*     struct ListNode* ptr; */
/*     int isFirst = 1; */ 
/*     while(list1 && list2){ */
/*         if (isFirst){ */
/*             if (list1 -> val < list2 -> val){ */
/*                 head = list1; */
/*                 list1 = list1 -> next; */
/*             } else{ */
/*                 head = list2; */
/*                 list2 = list2 -> next; */
/*             } */
/*             ptr = head; */
/*             isFirst = 0; */
/*         }else{ */
/*             if (list1 -> val < list2 ->val){ */
/*                 ptr -> next = list1; */
/*                 list1 = list1 -> next; */
/*             }else{ */
/*                 ptr -> next = list2; */
/*                 list2 = list2 -> next; */
/*             } */
/*             ptr = ptr -> next; */
/*         } */
/*     } */
/*     if (!list1) ptr -> next = list2; */
/*     if (!list2) ptr -> next = list1; */
/*     return head; */

/* } */

// (Kind of Solution
/* struct ListNode* mergeTwoLists(struct ListNode * list1, struct ListNode * list2){ */
/*     struct ListNode* head=malloc(sizeof(struct ListNode)); */
/*     struct ListNode* ptr = head; */
/*     while(list1 && list2){ */
/*         if (list1 -> val < list2 -> val){ */
/*             ptr -> next = list1; */
/*             list1 = list1 -> next; */
/*         } else{ */
/*             ptr -> next = list2; */
/*             list2 = list2 -> next; */
/*         } */

/*         ptr = ptr -> next; */
/*     } */
/*     if (!list1) ptr -> next = list2; */
/*     if (!list2) ptr -> next = list1; */
/*     return head->next ; */
/* } */


struct ListNode* mergeTwoLists(struct ListNode * list1, struct ListNode * list2){
    struct ListNode* head;
    struct ListNode** ptr = &head;
    struct ListNode** node;
    for (node=NULL ; list1 && list2 ; *node = (*node) -> next ){
        node = list1 -> val < list2 -> val ? &list1 : &list2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }

    *ptr = (struct ListNode *)((uintptr_t) list1 | (uintptr_t) list2);

    return head ;
}

int main(){
    struct ListNode lst1;
    struct ListNode val0;
    struct ListNode val1;
    /* struct ListNode val2; */
    lst1.val = 1;
    val0.val = 2;
    val1.val = 4;

    lst1.next = &val0;
    val0.next = &val1;
    val1.next = NULL;
    /* val2.next = NULL; */

    struct ListNode lst2;
    struct ListNode val3;
    struct ListNode val5;
    lst2.val = 1;
    val3.val = 3;
    val5.val = 4;
    lst2.next = &val3;
    val3.next = &val5;
    val5.next = NULL;


    struct ListNode* merged = mergeTwoLists(&lst1, &lst2);
    while (merged){
        printf("%d ", merged->val);
        merged = merged ->next;
    }

    return 0;
}
