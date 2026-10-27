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
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node *root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main(void) {
    int values[] = {13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18};
    int n = sizeof(values) / sizeof(values[0]);
    struct Node *root = NULL;
    int i, choice, key;

    for (i = 0; i < n; i++)
        root = insert(root, values[i]);

    while (1) {
        printf("\n--- BST of Given Integers ---\n");
        printf("1.Inorder  2.Preorder  3.Postorder  4.Search  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inorder(root); printf("\n"); break;
            case 2:
                preorder(root); printf("\n"); break;
            case 3:
                postorder(root); printf("\n"); break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                printf(search(root, key) ? "Key found.\n" : "Key not found.\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
