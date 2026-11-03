#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};



bool hasCycle(struct ListNode *head) {
    
    // empty or 1 node only
    if(head == NULL || head->next == NULL)
        return false;

    struct ListNode *sptr = head;               // slow pointer , one step at a time  
    struct ListNode *fptr = head;               // fast pointer , two step at a time  
    while(fptr != NULL && fptr->next != NULL) {
        sptr = sptr->next;
        fptr = fptr->next->next;
        if(sptr == fptr)
            return true;
    }
    return false;
}


int main()
{

 
    return 0;
}