#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int length = 0;
    struct ListNode *cur = head;
    struct ListNode *prev;

    while(cur != NULL) {
        cur = cur->next;
        length++;
    }

    k = k % length;
    if(k == 0)
        return head;
        
    cur = head;
    for(int i = 0; i < k; i++)
        cur = cur->next;

    prev = head;
    while(cur->next != NULL){
        prev = prev->next;
        cur = cur->next;
    }

    struct ListNode *res = prev->next;
    prev->next = NULL;
    cur->next = head;
    return res;
}

int main()
{

    printf("61 problem");

    return 0;
}