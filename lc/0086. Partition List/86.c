struct ListNode {
    int val;
    struct ListNode *next;
};
// nice first time right with double pointer. Good!!
struct ListNode *partition(struct ListNode *head, int x)
{
    if (!head)
        return NULL;
    struct ListNode *left = NULL;
    struct ListNode *right = NULL;
    struct ListNode **ptr_left = &left;
    struct ListNode **ptr_right = &right;

    for (struct ListNode *it = head; it; it = it->next) {
        if (it->val < x) {
            *ptr_left = it;
            ptr_left = &(*ptr_left)->next;
        } else {
            *ptr_right = it;
            ptr_right = &(*ptr_right)->next;
        }
    }
    *ptr_right = NULL;
    *ptr_left = right;
    return left;
}

int main()
{
    return 0;
}
