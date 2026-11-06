#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


bool isPalindrome(struct ListNode* head) {

    // 1 node 
    if(head->next == NULL)
        return head;

    // 2 nodes
    if(head->next != NULL && head->next->next == NULL)
    {
        if(head->val == head->next->val)
            return true;
        else
            return false;
    }
     
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // find the middle
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second middle
    struct ListNode* prev = NULL;
    struct ListNode* cur  = slow;
    struct ListNode* next = NULL;

    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    cur = prev;
    // checking every node linearly
    while(head && cur)
    {
        if(head->val != cur->val)
            return false;
        head = head->next;
        cur = cur->next;
    }
    
    return true;
}


int main()
{
    printf("234 problem");

    return 0;
}