#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ---------- Stack using Array ---------- */
int stack[MAX];
int top = -1;

void arrayPush(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = value;
}

void arrayPop(void) {
    if (top == -1) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void arrayDisplay(void) {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/* ---------- Stack using Linked List ---------- */
struct Node {
    int data;
    struct Node *next;
};

struct Node *topNode = NULL;

void linkedPush(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

void linkedPop(void) {
    struct Node *temp;

    if (topNode == NULL) {
        printf("Stack underflow.\n");
        return;
    }

    temp = topNode;
    printf("Popped: %d\n", temp->data);
    topNode = topNode->next;
    free(temp);
}

void linkedDisplay(void) {
    struct Node *temp = topNode;

    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Stack ---\n");
        printf("1.Array Push  2.Array Pop  3.Array Display\n");
        printf("4.Linked Push  5.Linked Pop  6.Linked Display  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &value);
                arrayPush(value); break;
            case 2:
                arrayPop(); break;
            case 3:
                arrayDisplay(); break;
            case 4:
                printf("Value: "); scanf("%d", &value);
                linkedPush(value); break;
            case 5:
                linkedPop(); break;
            case 6:
                linkedDisplay(); break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
