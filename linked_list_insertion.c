#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int val;
    struct node*next;
}node;
void insert( node**head,node**tail,int val)
{
    node*newnode=(node*)malloc(sizeof(node));
      newnode->val=val;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
        return;
    }
    (*tail)->next=newnode;
   (*tail)=(*tail)->next;
    
}
void insert_at_head(node**head,int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->next=NULL;
    newnode->next=*head;
    *head=newnode;
}
void insert_at_tail(node**head,node**tail,int val)
{
     node*newnode=(node*)malloc(sizeof(node));
      newnode->val=val;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
        return;
    }
    (*tail)->next=newnode;
   (*tail)=(*tail)->next;
}
void insert_at_any_position(node**head,int val,int pos)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->next=NULL;
   
    if(pos==0||*head==NULL)
    {
        newnode->next=*head;
        *head=newnode;
        return;
    }
    node*temp=*head;
    for(int i=0;i<pos-1;i++)
    { 
        if (temp == NULL) { // invalid position
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position\n");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void print_list(node*head)
{
     printf("Print the list:");
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head=head->next;
    }
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
        insert(&head,&tail,val);
    //   insert_at_tail(&head,&tail,val);
    }
   print_list(head);
   printf("Enter value position for add value of list:");
    int val,pos;
    scanf("%d %d",&val,&pos);
    insert_at_any_position(&head,val,pos);
   print_list(head);

    
    return 0;
}