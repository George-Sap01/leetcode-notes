#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *second_node = head->next;
    struct ListNode *first_node  = head;

    first_node->next = swapPairs(head->next->next);
    second_node->next = first_node;
    
    return second_node;
}


int main()
{

    return 0;
}