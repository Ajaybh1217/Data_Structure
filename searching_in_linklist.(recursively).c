#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
int count=0;
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
void search(struct node *href,int data)
{
    if(href==NULL)
        printf("element does not exit");
    else
    {
        if(href->data==data)
        {
            printf("\nElement %d found at %d index",href->data,count);
            return ;
        }
        count=count+1;
        href=href->next;
        search(href,data);
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
    search(head,40);
    return 0;
}




