#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate key %d ignored.\n", value);

    return root;
}

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node *minValueNode(struct Node *root) {
    struct Node *current = root;

    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int key) {
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void) {
    struct Node *root = NULL;
    struct Node *result;
    int choice, value;

    while (1) {
        printf("\n--- BST ---\n");
        printf("1.Insert  2.Delete  3.Search  4.Inorder  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Value to delete: ");
                scanf("%d", &value);
                if (search(root, value) == NULL)
                    printf("Key not found.\n");
                else
                    root = deleteNode(root, value);
                break;

            case 3:
                printf("Key to search: ");
                scanf("%d", &value);
                result = search(root, value);
                printf(result ? "Key found.\n" : "Key not found.\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
