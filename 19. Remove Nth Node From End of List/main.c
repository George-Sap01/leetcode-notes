#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *cur = head;
    struct ListNode *prev = head;
    
    for(int i = 0; i < n; i++)
        cur = cur->next;

    if(n == 1 && cur == NULL)
        return NULL;

    if(cur == NULL){
        head = head->next;
        return head;
    }

    while(cur != NULL)
    {
        if(cur->next == NULL)
            break;
        cur = cur->next;
        prev = prev->next;
    }
    
    if(n == 1)
        prev->next = NULL;
    else
        prev->next = prev->next->next;


    return head;
}


int main()
{
    printf("Hello Leetcode");

    return 0;
}