#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node *root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find minimum node in a subtree
struct Node* findMin(struct Node *root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Delete a node
struct Node* deleteNode(struct Node *root, int value) {

    if (root == NULL) {
        return NULL;
    }

    // Search in left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    // Node found
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main() {

    struct Node *root = NULL;
    int n, value, deleteValue;
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("\nInorder after deletion: ");
    inorder(root);

    printf("\n");

    return 0;
}