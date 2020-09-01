#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
    struct Node *head;
    void (*printList)(struct Node *head);
    void (*insertNode)(int data, struct Node **head);
    void (*deleteNode)(int data, struct Node **head);
};


struct Node* createNode(int data){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head){
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/* INSERT ELEMENT TO THE END OF A LIST */
void insertNode(int data, struct Node **head){

    if (*head == NULL){
        *head = createNode(data);
    }else {
        struct Node *prevNode, *currentNode = *head;
        while (currentNode != NULL) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = createNode(data);
    }

}

void deleteNode(int data, struct Node **head)
{
    struct Node *prevNode = *head, *currentNode = *head;

    while (currentNode != NULL && currentNode->data == data){
        *head = currentNode->next;
        currentNode = *head;
    }

    while (currentNode != NULL){
        if (currentNode->data == data){
            prevNode->next = currentNode->next;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

}



int main(){
    struct LinkedList list;
    list.head = NULL;
    list.printList = &printList;
    list.insertNode = &insertNode;
    list.deleteNode = &deleteNode;
    list.insertNode(5, &list.head);
    list.insertNode(6, &list.head);
    list.deleteNode(5, &list.head);
    list.printList(list.head);

}