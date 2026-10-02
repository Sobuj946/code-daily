#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define M 5
int stack[M];
int top=-1;
int sz=0;
void push(int val)
{
    if(top==M-1)
    {
        printf("The stack is overflow\n");
        return;
    }
    stack[++top]=val;
    sz++;

}
void pop()
{
    if(top==-1)
    {
        printf("The stack is underflow\n");
        return;
    }
    top--;
    sz--;
}
void peek()
{
    if(top==-1)
    {
        printf("The stack is underflow\n");
        return;
    }
    printf("The peek value is:%d\n ",stack[top]);
        
}
void size()
{
    printf("sz is:%d\n",sz);
}
int empty()
{
  return -1;
}
void display()
{
    printf("display all value:\n");
    int temp=top;
    while(temp!=-1)
    {
        printf("%d ",stack[temp]);
        temp--;
    }
    printf("\n");
}
int main(){

    while(true)
    {
        int val;
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        push(val);
    }
    display();
    peek();
    pop();
    peek();
    size();
    
    return 0;
}