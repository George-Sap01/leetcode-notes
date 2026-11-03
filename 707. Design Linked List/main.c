#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
} Node;


typedef struct LinkedList{
    Node *head;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {

    MyLinkedList* ll = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    ll->head = NULL;
    ll->size = 0;
    return ll;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    
    // linked list is empty
    if(obj->head == NULL || obj->size <= index) return -1;
    
    Node *cur = obj->head;
    int cnt = 0;
    while(cnt < index) {
        cur = cur-> next;
        cnt++;
    }

    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) exit(0);

    newnode->next = obj->head;
    newnode->val = val;
    obj->head = newnode;    
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    
    if(obj->size == 0)
        return myLinkedListAddAtHead(obj, val);

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) exit(0);
    
    Node* cur = obj->head;
    Node* prev;
    while(cur != NULL) {
        prev = cur;
        cur = cur->next;
    }    

    newnode->next = NULL;
    newnode->val = val;
    prev->next = newnode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if(obj->size < index)
        return ;

    if(index == 0)
        return myLinkedListAddAtHead(obj, val);

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) exit(0);
    
    int cnt = 0;
    Node *cur = obj->head;
    Node *prev = cur;
    while(cnt < index) {
        cnt++;
        prev = cur;
        cur = cur->next;
    }

    newnode->next = prev->next;
    newnode->val = val;
    prev->next = newnode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
    if (index < 0 || index >= obj->size) return;

    if(index == 0) {
        Node *cur = obj->head;
        obj->head = cur->next;
        free(cur);
        obj->size--;
        return ;
    }

    int cnt = 0;
    Node *cur = obj->head;
    Node *prev = cur;
    while(cnt < index) {
        cnt++;
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    free(cur);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *temp;
    Node *cur = obj->head;
    while(cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

void printll(MyLinkedList* obj)
{

    if(obj->size == 0) return ;

    Node* cur = obj->head;
    printf("LINKED LIST: ");
    while(cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("\n\n");
}

int main()
{
    int index = 1;
    int val = 20;
    MyLinkedList* obj = myLinkedListCreate();
    
    
    myLinkedListAddAtHead(obj, 6);
    printll(obj);
    myLinkedListAddAtHead(obj, 2);
    printll(obj);

    printf("%d\n", myLinkedListGet(obj, 0));
    printf("%d\n", myLinkedListGet(obj, 1));


    myLinkedListAddAtHead(obj, 1);
    printll(obj);
    myLinkedListAddAtTail(obj, 9);
    printll(obj);
    myLinkedListAddAtTail(obj, 4);
    printll(obj);
    printf("%d\n", myLinkedListGet(obj, 3));

    myLinkedListAddAtTail(obj, 4);
    printll(obj);
    printf("%d\n", myLinkedListGet(obj, 6));
    
    myLinkedListAddAtIndex(obj, 1, 1);
    printll(obj);

    // addAtHead   addAtHead   get       get   addAtHead   addAtTail  
    // [6]          [2]        [0]       [1]   [1]            [9]     
    // addAtTail   get      addAtTail   get   addAtIndex
    // [4]       [3]        [4]       [6]     [1,1]

    // myLinkedListFree(obj);
    // printll(obj);

    return 0;
}