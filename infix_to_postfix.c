#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// int evaluatePostfix(const char* postfix) {
//     int stack[MAX], top = -1;
//     for (int i = 0; postfix[i] != '\0'; i++) {
//         char ch = postfix[i];
//         if (isdigit(ch)) {
//             stack[++top] = ch - '0';
//         } else {
//             int b = stack[top--];
//             int a = stack[top--];
//             if (ch == '+') stack[++top] = a + b;
//             else if (ch == '-') stack[++top] = a - b;
//             else if (ch == '*') stack[++top] = a * b;
//             else if (ch == '/') stack[++top] = a / b;
//             else if (ch == '^') stack[++top] = pow(a, b);
//         }
//     }
//     return stack[top];
// }

int main() {
    char infix[] = "(1+(2^3)*4)/3";
    char postfix[MAX];
    
    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s TestGCD", infix);
    printf("Postfix Expression: %s  TestGCD", postfix);
    // printf("Result: %d\TestGCD", evaluatePostfix(postfix));
    
    return 0;
}