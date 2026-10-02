#include<stdio.h>
#include<math.h>
#define sz 5
int pqueue[sz];
int item[sz];
int rear=-1,front=-1;
void enqueue(int data, int priority)
{
    if(rear==sz-1)
    {
        printf("Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
        item[rear]=data;
        pqueue[rear]=priority;
        return;
    }
    int i;
    for( i=rear;i>=front;i--)
    {
        if(priority>pqueue[i])
        {
            item[i+1]=item[i];
            pqueue[i+1]=pqueue[i];
        }
        else
        {
            break;
        }
    }
    item[i+1]=data;
    pqueue[i+1]=priority;
    rear++;
}
void dequeue()
{
    
}
int main(){

    
    return 0;
}