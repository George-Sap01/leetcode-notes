#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode* newHead;
    struct ListNode* cur;

    if(list1 == NULL && list2 == NULL)  
        return NULL;

    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
       return list1;

    if(list1->val < list2->val) {
        newHead = list1;
        list1 = list1->next;
    }
    else {
        newHead = list2;
        list2 = list2->next;
    }
    cur = newHead;

    while(list1 && list2)
    {
        if(list1->val > list2->val) {
            
            cur->next = list2;
            list2 = list2->next;
        }    
        else {
            cur->next = list1;
            list1 = list1->next;
        }

        cur = cur->next;
    }

    if(list1 == NULL && list2 == NULL)
        cur->next = NULL;
    else if (list1 == NULL)
        cur->next = list2;
    else
        cur->next = list1;

    return newHead;
}


struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode dummy;
    struct ListNode *cur = &dummy;
    
    while(list1 && list2)
    {
        if(list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        }    
        else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }

    if(list1 == NULL && list2 == NULL)
        cur->next = NULL;
    else if (list1 == NULL)
        cur->next = list2;
    else
        cur->next = list1;

    return dummy.next;
}



int main()
{
    printf("21 Problem");


    return 0;
}