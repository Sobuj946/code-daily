#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define M 100
int top = -1;
char stack[M];
void push(int ch)
{
    stack[++top] = ch;
}
int pop()
{
    return stack[top--];
}
int evaluatepostfix(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch (ch)
            {
            case '+':
                push(val1 + val2);
                break;
            case '-':
                push(val1 - val2);
                break;
            case '*':
                push(val1 * val2);
                break;
            case '/':
                push(val1 / val2);
                break;
            case '^':
            {
                int result = 1;
                for (int j = 0; j < val1; j++)
                {
                    result *= val1;
                }
                push(result);
            }
            break;
            }
        }
    }
    return pop();
}
int main()
{
    char exp[M];
    scanf("%s", exp);
    int result = evaluatepostfix(exp);
    printf("%d", result);
    return 0;
}