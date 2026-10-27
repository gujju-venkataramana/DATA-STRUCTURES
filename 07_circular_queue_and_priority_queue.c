#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ---------- Circular Queue using Array ---------- */
int cq[MAX];
int cf = -1, cr = -1;

void circularEnqueue(int value) {
    if ((cr + 1) % MAX == cf) {
        printf("Circular queue is full.\n");
        return;
    }

    if (cf == -1)
        cf = cr = 0;
    else
        cr = (cr + 1) % MAX;

    cq[cr] = value;
}

void circularDequeue(void) {
    if (cf == -1) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Deleted: %d\n", cq[cf]);

    if (cf == cr)
        cf = cr = -1;
    else
        cf = (cf + 1) % MAX;
}

void circularDisplay(void) {
    int i;

    if (cf == -1) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    i = cf;

    while (1) {
        printf("%d ", cq[i]);
        if (i == cr)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* ---------- Priority Queue ---------- */
/* Smaller priority number means higher priority. */
struct PNode {
    int data;
    int priority;
    struct PNode *next;
};

struct PNode *pfront = NULL;

void priorityEnqueue(int value, int priority) {
    struct PNode *newNode = malloc(sizeof(struct PNode));
    struct PNode *temp;

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if (pfront == NULL || priority < pfront->priority) {
        newNode->next = pfront;
        pfront = newNode;
        return;
    }

    temp = pfront;
    while (temp->next != NULL &&
           temp->next->priority <= priority)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void priorityDequeue(void) {
    struct PNode *temp;

    if (pfront == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    temp = pfront;
    printf("Deleted: %d (priority %d)\n",
           temp->data, temp->priority);

    pfront = pfront->next;
    free(temp);
}

void priorityDisplay(void) {
    struct PNode *temp = pfront;

    if (temp == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("[%d,p=%d] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    int choice, value, priority;

    while (1) {
        printf("\n--- Circular Queue / Priority Queue ---\n");
        printf("1.CQ Enqueue  2.CQ Dequeue  3.CQ Display\n");
        printf("4.PQ Enqueue  5.PQ Dequeue  6.PQ Display  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &value);
                circularEnqueue(value); break;
            case 2:
                circularDequeue(); break;
            case 3:
                circularDisplay(); break;
            case 4:
                printf("Value and priority: ");
                scanf("%d%d", &value, &priority);
                priorityEnqueue(value, priority); break;
            case 5:
                priorityDequeue(); break;
            case 6:
                priorityDisplay(); break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
