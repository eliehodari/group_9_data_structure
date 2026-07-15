#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insertNode(root->left, value);
    else if (value > root->data) root->right = insertNode(root->right, value);
    return root;
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

#define MAX_NODES 100

void levelOrder(Node *root) {
    Node *queue[MAX_NODES];
    int front = 0, rear = 0;
    Node *current;

    if (root == NULL) return;

    queue[rear++] = root;

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int numValues = 8;
    int i;

    printf("Binary Search Tree Demonstration\n");
    printf("---------------------------------\n");

    printf("Inserting values: ");
    for (i = 0; i < numValues; i++) {
        printf("%d ", values[i]);
        root = insertNode(root, values[i]);
    }
    printf("\n");

    printf("\nBreadth-First Traversal (level order): ");
    levelOrder(root);
    printf("\n");

    printf("\nDepth-First Traversal (pre-order): ");
    preOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
