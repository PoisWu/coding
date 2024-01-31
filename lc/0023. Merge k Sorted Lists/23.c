#include <stddef.h>
#include <stdint.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head;
    struct ListNode **ptr = &head;
    struct ListNode **node;
    for (node = NULL; list1 && list2; *node = (*node)->next) {
        node = list1->val < list2->val ? &list1 : &list2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }

    *ptr = (struct ListNode *) ((uintptr_t) list1 | (uintptr_t) list2);

    return head;
}

// v1 merge with first element
/* struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){ */
/*     if (listsSize == 0) return NULL; */
/*     for (int i = 1; i< listsSize;i++) */
/*         lists[0] = mergeTwoLists(lists[0], lists[i]); */
/*     return lists[0]; */
/* } */

// v2  head - tail
/* struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) { */
/*     if (listsSize == 0) return NULL; */
/*     while(listsSize > 1){ */
/*         for (int i = 0; i< listsSize/2 ; ++i) */
/*             lists[i] = mergeTwoLists(lists[i], lists[listsSize-i-1]); */
/*         listsSize -= listsSize/2; */
/*     } */
/*     return lists[0]; */

/* } */

// v3 分段
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;
    while (listsSize > 1) {
        for (int i = 0; i < listsSize / 2; ++i)
            lists[i] = mergeTwoLists(lists[i], lists[listsSize - i - 1]);
        listsSize -= listsSize / 2;
    }
    return lists[0];
}


int main()
{
    return 0;
}
