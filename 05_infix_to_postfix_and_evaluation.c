#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop(void) {
    return stack[top--];
}

char peek(void) {
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isspace((unsigned char)c))
            continue;

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (top != -1)
                pop();
        } else if (isOperator(c)) {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int intStack[MAX];
int intTop = -1;

void ipush(int value) {
    intStack[++intTop] = value;
}

int ipop(void) {
    return intStack[intTop--];
}

int evaluatePostfix(char postfix[]) {
    int i, a, b;
    char c;

    intTop = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];

        if (isdigit((unsigned char)c)) {
            ipush(c - '0');
        } else if (isOperator(c)) {
            b = ipop();
            a = ipop();

            switch (c) {
                case '+': ipush(a + b); break;
                case '-': ipush(a - b); break;
                case '*': ipush(a * b); break;
                case '/': ipush(a / b); break;
                case '^': {
                    int result = 1, k;
                    for (k = 0; k < b; k++) result *= a;
                    ipush(result);
                    break;
                }
            }
        }
    }

    return ipop();
}

int main(void) {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single-digit operands for evaluation): ");
    scanf(" %199[^\n]", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    /* Evaluation is valid when operands are single decimal digits. */
    printf("Postfix evaluation: %d\n", evaluatePostfix(postfix));

    return 0;
}
