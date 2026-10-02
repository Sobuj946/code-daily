#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node*next;
}node;
void insert_at_tail(node**head,node**tail,int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=*tail=newnode;
        return;
    }
    (*tail)->next=newnode;
    (*tail)=(*tail)->next;
}
void delete_at_head(node**head)
{   if(*head==NULL)
    {
        printf("Underflow list\n");
        return;
    }
    node*del=*head;
    (*head)=(*head)->next;
    free(del);
}
void delete_at_any_position(node**head,int pos)
{
    if(*head==NULL)
    {
        printf("Underflow list\n");
        return;
    }
    node*temp=*head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    if(pos<0||pos>cnt)
    {
        printf("Not valid position\n");
        return;
    }
    else
    {
        temp=*head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    node*del=temp->next;
    temp->next=del->next;
    free(del);
    }
}
void delete_at_tail(node**head,node**tail)
{
    if(*head==NULL)
    {
        printf("The list is underflow\n");
        return;
    }
    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return;
    }
    node*temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node*del=temp->next;
    *tail=temp;
    temp->next=NULL;
    
    free(del);
}
void print(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    while(true)
    {
        int val;
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        insert_at_tail(&head,&tail,val);
    }
    print(head);
    delete_at_head(&head);
    print(head);
    int pos;
    scanf("%d",&pos);
    delete_at_any_position(&head,pos);
    print(head);
    delete_at_tail(&head,&tail);
    print(head);
    
    return 0;
}