#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *new_head;
    struct ListNode *cur;
    int carry = 0;

    int temp_val;

    temp_val = l1->val + l2->val;
    new_head = newnode(temp_val % 10);
    carry = temp_val / 10;
    l1 = l1->next;
    l2 = l2->next;
    
    cur = new_head;
    while(l1 && l2)
    {
        temp_val = l1->val + l2->val;
        cur->next = newnode((temp_val + carry) % 10);
        cur = cur->next;
        carry = (temp_val + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 == NULL && l2 == NULL){
        if(carry)
            cur->next = newnode(1);
        return new_head;
    }

    if(l1 == NULL){
        while(l2) {
            cur->next = newnode((l2->val + carry) % 10);
            cur = cur->next;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
    }
    else {
        while(l1) {
            cur->next = newnode((l1->val + carry) % 10);
            cur = cur->next;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
    }


    if(carry)
        cur->next = newnode(1);

    return new_head;
}

struct ListNode* newnode(int val) {

    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->next = NULL;
    newNode->val = val; 
    return newNode;
}


struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;
    }

    return dummy.next;
}


int main()
{

    return 0;
}