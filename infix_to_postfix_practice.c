#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define M 100
char stack[M];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
void infixtopostfix(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                printf("%c", pop());
            }
            push(ch);
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}
int main()
{

    char exp[100];
    scanf("%s", exp);
    infixtopostfix(exp);
    return 0;
}