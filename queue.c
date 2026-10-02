#include<stdio.h>
#include<math.h>
#define M 100
int queue[M];
int front=-1;
int rear=-1;
int sz=0;
void push(int val)
{
    if(rear==M-1)
    {
        printf("The queue is overloaded\n");
        return;
    }
    rear++;
    if(front==-1)
    {
        front=0;
    }
    sz++;
    queue[rear]=val;

}
void pop()
{
    if(front==-1||front>rear)
    {
        printf("Underflow queue\n");
        return;
    }
    printf("The queue pop value is:%d\n",queue[front]);
    front++;
    sz--;
}
void size()
{
    printf("The queue size is:%d\n",sz);
}
void empty()
{
    if(front==-1&&rear==-1)
    {
        printf("Empty queue\n");
        return;
    }
}
void display()
{
    int f=front;
    printf("Display the queue value:\n");
    for(int i=f;i<=rear;i++)
    {
        printf("%d ",queue[i]);
        
    }
    printf("\n");
}
int main(){

    while(1)
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
    pop();
    display();
    size();

    return 0;
}