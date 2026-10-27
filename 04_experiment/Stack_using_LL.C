#include <stdio.h>
#include <stdlib.h>

/* node structure for the linked list */
struct Node {
int data;
struct Node *next;
};
struct Node *top = NULL;

/* check if stack is empty */
int isEmpty() {
return top == NULL;
}

/* push an element onto the stack */
void push(int val) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Stack Overflow (memory allocation failed)\n");
return;
}
newNode->data = val;
newNode->next = top;
top = newNode;
printf("Pushed %d\n", val);
}

/* pop an element from the stack */
void pop() {
if (isEmpty()) {
printf("Stack Underflow\n");
return;
}
struct Node *temp = top;
printf("Popped %d\n", temp->data);
top = top->next;
free(temp);
}

/* view the top element without removing it */
void peek() {
if (isEmpty()) {
printf("Stack is empty\n");
return;
}
printf("Top element: %d\n", top->data);
}

/* print all elements of the stack */
void display() {
if (isEmpty()) {
printf("Stack is empty\n");
return;
}
struct Node *ptr = top;
printf("Stack (top -> bottom): ");
while (ptr != NULL) {
printf("%d ", ptr->data);
ptr = ptr->next;
}
printf("\n");
}
int main() {
int choice, val;
while (1) {
printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter 'only numbers' to push: ");
scanf("%d", &val);
push(val);
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}