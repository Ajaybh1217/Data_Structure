#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
void printlist(struct node* n)
{
    while(n!='\0')
    {
        //n->data=30;
        printf("%d ",n->data);
        n=n->next;
    }
}
void append(struct node** href,int data)
{
    struct node *newnode;
    struct node *ptr;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    ptr=(*href);
    if(ptr==NULL)
    {
        (*href)=newnode;
        return;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;

    }
    ptr->next=newnode;
    newnode->data=data;
    return ;

}
void push(struct node** href,int data)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=(*href);
    (*href)=newnode;
    return;
}
void insertafter(struct node* prev,int data)
{
    if(prev==NULL)
    {
        printf("given previous node can not be null");
        return ;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=prev->next;
    prev->next=newnode;

}
int main()
{
    struct node* head=NULL;
    append(&head,15);
    append(&head,2);
    push(&head,10);
    push(&head,56);
    push(&head,65);
    insertafter(head->next,20);
    insertafter(head->next->next->next,20);


    printlist(head);
}
