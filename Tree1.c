#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* constructTree(int arr[], int n) {
    struct Node* root = newNode(arr[0]);
    int i;
    for (i = 1; i < n; i++) {
        insert(root, arr[i]);
    }
    return root;
}

void insert(struct Node* root, int data) {
    struct Node* temp = root;
    struct Node* new = newNode(data);
    struct Node* parent = NULL;
    while (temp != NULL) {
        parent = temp;
        if (temp->left == NULL) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if (parent->left == NULL) {
        parent->left = new;
    } else {
        parent->right = new;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = constructTree(arr, n);
    printf("Complete Binary Tree constructed successfully!\n");
    return 0;
}
