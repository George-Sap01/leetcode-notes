#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    // empty or 1 node only
    if(head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *prev = head;
    struct ListNode *slow = head;               // slow pointer , one step at a time  
    struct ListNode *fast = head;               // fast pointer , two step at a time  

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            if(prev == slow)
                return slow;
            if(prev->next == slow)
                return prev;

            slow = slow->next;
            while(prev->next != slow) {
                if(slow == fast)
                    prev = prev->next;

                slow = slow->next;
            }
            return prev->next;
        }
    }

    return NULL;
}

/* 
    # of steps of head to cycle start == # of steps where fast and slow meet to cycle start
    This happens because the slow pointer moves one step at a time, while the fast pointer moves two steps at a time.

    if (slow == fast) => this means that we have a cyclic linked list 
        then fast moves at one step at time too.
*/
struct ListNode *detectCycle2(struct ListNode *head) {
    if(head ==NULL || head->next ==NULL)
        return NULL;
    
    struct ListNode *slow=head;
    struct ListNode *fast=head;

    while(fast && fast->next) {

        fast=fast->next->next;
        slow=slow->next;
        
        if(slow == fast) {
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            if(slow == fast) {
                return slow;
            }
        }
    }
    return NULL;
}

int main()
{

 
    return 0;
}