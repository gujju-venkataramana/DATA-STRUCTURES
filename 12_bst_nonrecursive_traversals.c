#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value) {
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL) exit(1);
    p->data = value;
    p->left = p->right = NULL;
    return p;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;
    struct Node *current;

    if (root == NULL) return;

    stack[++top] = root;

    while (top != -1) {
        current = stack[top--];
        printf("%d ", current->data);

        if (current->right)
            stack[++top] = current->right;
        if (current->left)
            stack[++top] = current->left;
    }
}

void postorder(struct Node *root) {
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    struct Node *current;

    if (root == NULL) return;

    stack1[++top1] = root;

    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left)
            stack1[++top1] = current->left;
        if (current->right)
            stack1[++top1] = current->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

int main(void) {
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(values) / sizeof(values[0]);
    struct Node *root = NULL;
    int i, choice;

    for (i = 0; i < n; i++)
        root = insert(root, values[i]);

    while (1) {
        printf("\n--- BST Non-Recursive Traversals ---\n");
        printf("1.Inorder  2.Preorder  3.Postorder  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inorder(root); printf("\n"); break;
            case 2: preorder(root); printf("\n"); break;
            case 3: postorder(root); printf("\n"); break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
