#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {

    // Empty or 1 element only that isn't val
    if(head == NULL || (head->next == NULL && head->val != val))
        return head;

    // Multiple nodes with val in the beginning
    while(head->next != NULL) {
        if(head->val == val)
            head = head->next;
        else
            break;
    }
    // val NULL
    if(head->val == val && head->next == NULL)
        return NULL;

    // val not_val ...
    if(head->val == val && head->next != NULL)
        head = head->next;
    
    // not_val NULL
    if(head->next == NULL)
        return head;

    // Looking for val beyond the head
    struct ListNode* prev = head;
    struct ListNode* cur  = head->next;
    struct ListNode* next;
    
    while(cur->next != NULL) {
        next = cur->next;
        if(cur->val == val)
            prev->next = next;
        else
            prev = cur;    

        cur = next;
    }

    // check if the last node needs to be deleted
    if(cur->val == val)
        prev->next = NULL;

    return head;
}



struct ListNode* removeElements2(struct ListNode* head, int val) {
    
    // vals in the beginning
    while (head != NULL && head->val == val) {
        head = head -> next;
    }
    
    if(!head)
        return head;

    struct ListNode* temp = head;
    
    while(temp->next != NULL)
    {
        if(temp->next->val == val)
            temp->next = temp->next->next;
        else  
            temp = temp->next;
    }

    return head;
}


int main()
{

    return 0;
}