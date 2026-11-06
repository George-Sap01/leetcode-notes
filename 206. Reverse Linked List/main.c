#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
    // empty or 1 node length
    if(head == NULL || head->next == NULL)
        return head;

    // reverse the second middle
    struct ListNode* prev = NULL;
    struct ListNode* cur  = head;
    struct ListNode* next = NULL;

    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main()
{

    printf("206 problem");

    return 0;
}