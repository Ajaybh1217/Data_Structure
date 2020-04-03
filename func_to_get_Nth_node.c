#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node
{
    int data;
    struct node *next;
};
void printlist(struct node *n)
{
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n=n->next;
    }
    return;
}
void push(struct node **href,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(*href==NULL)
    {
        newnode->next=NULL;
        *href=newnode;
        return;
    }
    newnode->next=*href;
    *href=newnode;
}
int to_get_node(struct node* href,int index)
{
    int count=0;
    while(href!=NULL)
    {
        if(count==index)
            return href->data;
        href=href->next;
        count=count+1;
    }
    assert(0);
}
int main()
{
    struct node * head=NULL;
    push(&head,40);
    push(&head,50);
   // printlist(head);
    int result= to_get_node(head,6);
    printf("%d",result);

}
