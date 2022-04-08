#include <stdio.h>
#include <stdlib.h>

struct listNode {
  int data;
  struct listNode *link;
};
struct listNode *head;

int find(int);
int length();
void printList();
void insertNode(int);

void main() {

  struct listNode *node, *prevNode = NULL;
  int i;

  /* manual insertion of elements */
  for(i=10; i<=100; i+=10) {
        node = malloc(sizeof(*node));
        node->data = i;
        node->link = NULL;
        if(prevNode == NULL) head = node;
        else prevNode->link = node;
        prevNode = node;
  }

    insertNode(20);
    insertNode(5);
    insertNode(35);
    insertNode(1);

    printList();
    printf("result of finding %d: %d\n", 30, find(30));
    printf("number of integers in the list: %d\n", length());
}

int find(int key) {
    struct listNode *curr = head;
    int i = 0;

    while(curr) {
        if(curr->data == key) return i;
        i++;
        curr = curr->link;
    }
    return -1;
}

int length() {
    struct listNode *curr = head;
    int i = 0;

    while(curr) {
        i++;
        curr = curr->link;
    }
    return i;
}

void printList() {
    struct listNode* curr = head;
    int i = 0;

    printf("printList: ");
    while(curr) {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

void insertNode(int key) {
    struct listNode *node = NULL;
    struct listNode *curr = head;
    struct listNode *prev = NULL;

    if(find(key) >= 0) {
        printf("the key %d is already in the linked list.\n", key);
        return;
    }

    node = malloc(sizeof(*node));
    node->data = key;
    node->link = NULL;

    while(curr) {
        if(curr->data > key) break;
        prev = curr;
        curr = curr->link;
    }

    node->link = curr;

    if(prev == NULL) head = node;
    else prev->link = node;

    printf("insert %d in linked list.\n", key);
}
