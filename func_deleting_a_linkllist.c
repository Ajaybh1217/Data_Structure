#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
void delete_linklist(struct node **href)
{
    struct node *ptr;
    ptr=*href;
    while(ptr!=NULL)
    {
        *href=ptr->next;
        free(ptr);
        ptr=*href;
    }

}
void printlist(struct node* n)
{
    if(n==NULL)
    {
        printf("\nno element exits");
    }
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n=n->next;
    }
}
void push(struct node **href,int data)
{
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(*href==NULL)
    {
        newnode->next=NULL;
        *href=newnode;
        return ;
    }
    newnode->next=*href;
    *href=newnode;
}
int main()
{
    struct node* head=NULL;
    push(&head,40);
    push(&head,50);
    push(&head,60);
    push(&head,70);
    push(&head,80);
    printlist(head);
    delete_linklist(&head);
    printlist(head);
    return 0;
}
