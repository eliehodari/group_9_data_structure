#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node* insertAtHead(Node *head, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}


Node* insertAtTail(Node *head, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *current;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    return head;
}

Node* deleteByValue(Node *head, int value) {
    Node *current = head;
    Node *previous = NULL;

    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}


void printList(Node *head) {
    Node *current = head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    Node *head = NULL;

    printf("Singly Linked List Demonstration\n");
    printf("---------------------------------\n");

    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    printf("After inserting 10, 20, 30 at tail: ");
    printList(head);

    head = insertAtHead(head, 5);
    printf("After inserting 5 at head: ");
    printList(head);

    head = deleteByValue(head, 20);
    printf("After deleting value 20: ");
    printList(head);

    head = deleteByValue(head, 99);
    printf("After attempting to delete value 99: ");
    printList(head);

    freeList(head);
    return 0;
}
