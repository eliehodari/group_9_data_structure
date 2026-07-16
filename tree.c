#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into the Binary Search Tree
// Time Complexity: O(h), where h is the height of the tree
Node* insertNode(Node *root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Depth-First Traversal (Pre-order)
// Time Complexity: O(n)
void preOrder(Node *root) {

    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Breadth-First Traversal (Level Order)
// Time Complexity: O(n)
void levelOrder(Node *root) {

    if (root == NULL)
        return;

    Node *queue[MAX_NODES];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        Node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Search for a value in the tree
// Time Complexity: O(h)
Node* searchNode(Node *root, int value) {

    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchNode(root->left, value);

    return searchNode(root->right, value);
}

// Free allocated memory
void freeTree(Node *root) {

    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    Node *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int numValues = sizeof(values) / sizeof(values[0]);
    int i;
    int key;

    printf("=====================================\n");
    printf(" Binary Search Tree Demonstration\n");
    printf("=====================================\n\n");

    printf("Inserting values:\n");

    for (i = 0; i < numValues; i++) {
        printf("%d ", values[i]);
        root = insertNode(root, values[i]);
    }

    printf("\n");

    printf("\nBreadth-First Traversal (Level Order):\n");
    levelOrder(root);

    printf("\n");

    printf("\nDepth-First Traversal (Pre-order):\n");
    preOrder(root);

    printf("\n");

    // Search operation
    printf("\nEnter a value to search: ");
    scanf("%d", &key);

    if (searchNode(root, key) != NULL)
        printf("%d is found in the tree.\n", key);
    else
        printf("%d is NOT found in the tree.\n", key);

    freeTree(root);

    return 0;
}