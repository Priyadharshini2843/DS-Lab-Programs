#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

void push(char);
char pop();
int isEmpty();
void intoPost();
int space(char);
void print();
int precedence(char);

void evalPush(int);
int evalPop();
int evaluatePostfix();

int main() {
    printf("\nEnter the Infix Expression: ");
    scanf("%[^\n]", infix);   // allow input like "5+5+10" or with spaces
    intoPost();
    print();
    int result = evaluatePostfix();
    printf("Evaluation Result: %d\n", result);
    return 0;
}

void intoPost() {
    int i, j = 0;
    char next, symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            if (isdigit(symbol)) {
                // Read full number
                while (isdigit(infix[i])) {
                    postfix[j++] = infix[i++];
                }
                postfix[j++] = ' '; // delimiter
                i--; // step back
            } else {
                switch (symbol) {
                    case '(':
                        push(symbol);
                        break;
                    case ')':
                        while ((next = pop()) != '(') {
                            postfix[j++] = next;
                            postfix[j++] = ' ';
                        }
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                        while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                            postfix[j++] = pop();
                            postfix[j++] = ' ';
                        }
                        push(symbol);
                        break;
                    default:
                        printf("\nInvalid symbol: %c\n", symbol);
                        exit(1);
                }
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int space(char c) {
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void print() {
    printf("\nThe equivalent Postfix Expression: ");
    printf("%s", postfix);
    printf("\n");
}

void push(char c) {
    if (top == MAX - 1) {
        printf("\nStack Overflow");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("\nStack Underflow");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}

void evalPush(int val) {
    if (evalTop == MAX - 1) {
        printf("\nEvaluation Stack Overflow");
        exit(1);
    }
    evalStack[++evalTop] = val;
}

int evalPop() {
    if (evalTop == -1) {
        printf("\nEvaluation Stack Underflow");
        exit(1);
    }
    return evalStack[evalTop--];
}

int evaluatePostfix() {
    int i = 0;
    char token[20];
    int op1, op2, result;

    evalTop = -1;  // reset evaluation stack

    while (i < strlen(postfix)) {
        if (isdigit(postfix[i])) {
            int k = 0;
            while (isdigit(postfix[i])) {
                token[k++] = postfix[i++];
            }
            token[k] = '\0';
            evalPush(atoi(token));  // convert whole number
        } else if (postfix[i] == ' ') {
            i++;
        } else {
            op2 = evalPop();
            op1 = evalPop();
            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        printf("\nError: Division by zero\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
                case '^':
                    result = 1;
                    for (int k = 0; k < op2; k++)
                        result *= op1;
                    break;
                default:
                    printf("\nInvalid operator: %c\n", postfix[i]);
                    exit(1);
            }
            evalPush(result);
            i++;
        }
    }
    return evalPop();
}
