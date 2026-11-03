#include <stdio.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    // first a pointer goes till the end 
    int size = 3 * 10 * 10 * 10 * 10; 
    struct ListNode * arr[size];
    int index = 0;
    while(headA != NULL) {
        arr[index] = headA;
        headA =  headA->next;
        index++;
    }

    while(headB != NULL)
    {
        for(int i = 0; i < index; i++)
            if(headB == arr[i])
                return headB;
         headB = headB->next;
    }

    return NULL;
}

struct ListNode *getIntersectionNode2(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == headB)
        return headA; 
    
    struct ListNode *first = headA;
    struct ListNode *second = headB;

    while(first != NULL || second != NULL)
    {
        first = (first == NULL) ? headB : first->next;
        second = (second == NULL) ? headA : second->next;
        if(first == second)
            return first;
    }

    return NULL;
}


int main()
{
    printf("Hello world\n");

    return 0;
}