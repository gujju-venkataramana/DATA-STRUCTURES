#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isFull(void) {
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

int isEmpty(void) {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = value;
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    deque[rear] = value;
}

void deleteFront(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void deleteRear(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display(void) {
    int i;

    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Deque using Circular Array ---\n");
        printf("1.Insert Front  2.Insert Rear  3.Delete Front\n");
        printf("4.Delete Rear  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &value);
                insertFront(value); break;
            case 2:
                printf("Value: "); scanf("%d", &value);
                insertRear(value); break;
            case 3:
                deleteFront(); break;
            case 4:
                deleteRear(); break;
            case 5:
                display(); break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
