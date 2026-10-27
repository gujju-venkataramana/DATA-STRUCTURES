#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ---------- Queue using Array ---------- */
int q[MAX];
int front = -1, rear = -1;

void arrayEnqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow.\n");
        return;
    }

    if (front == -1)
        front = 0;

    q[++rear] = value;
}

void arrayDequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue underflow.\n");
        return;
    }

    printf("Deleted: %d\n", q[front++]);

    if (front > rear)
        front = rear = -1;
}

void arrayDisplay(void) {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

/* ---------- Queue using Linked List ---------- */
struct Node {
    int data;
    struct Node *next;
};

struct Node *frontNode = NULL;
struct Node *rearNode = NULL;

void linkedEnqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rearNode == NULL)
        frontNode = rearNode = newNode;
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void linkedDequeue(void) {
    struct Node *temp;

    if (frontNode == NULL) {
        printf("Queue underflow.\n");
        return;
    }

    temp = frontNode;
    printf("Deleted: %d\n", temp->data);

    frontNode = frontNode->next;

    if (frontNode == NULL)
        rearNode = NULL;

    free(temp);
}

void linkedDisplay(void) {
    struct Node *temp = frontNode;

    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Queue ---\n");
        printf("1.Array Enqueue  2.Array Dequeue  3.Array Display\n");
        printf("4.Linked Enqueue  5.Linked Dequeue  6.Linked Display  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &value);
                arrayEnqueue(value); break;
            case 2:
                arrayDequeue(); break;
            case 3:
                arrayDisplay(); break;
            case 4:
                printf("Value: "); scanf("%d", &value);
                linkedEnqueue(value); break;
            case 5:
                linkedDequeue(); break;
            case 6:
                linkedDisplay(); break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
