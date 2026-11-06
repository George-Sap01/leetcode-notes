#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    
    // empty or 1 or 2 nodes only
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    // 3 nodes at least
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *cur = even->next;

    struct ListNode *link = even;
    struct ListNode *res = odd;
    int index = 1;

    while(cur != NULL)
    {
        // even index
        if(index % 2 == 0) {
            even->next = cur;
            even  = even->next;
        } // odd index
        else{   
            odd->next = cur;
            odd  = odd->next;
        }
        
        index++;
        cur = cur->next;
    }

    odd->next = link;
    even->next = NULL;
    return res;
} 


struct ListNode* oddEvenList2(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main()
{

    printf("328 problem");

    return 0;
}