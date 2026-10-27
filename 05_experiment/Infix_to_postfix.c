#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push an operator/bracket onto the stack */
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

/* Pop an operator/bracket from the stack */
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

/* Checking associativity */
char associativity(char ch) {
    if (ch == '^')
        return 'r';  // Right-to-left
    else if (ch == '+' || ch == '-' ||
             ch == '*' || ch == '/')
        return 'l';  // Left-to-right
    else
        return '\0';
}

/* Return precedence of an operator */
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

/* Check if character is an operator */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            // Operand: copy directly to output
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1 && stack[top] == '(')
                pop();  // Remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) &&
                    associativity(ch) == 'l'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s",&infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}