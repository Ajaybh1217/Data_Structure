#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node
{
    int data;
    struct node *next;
};

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
int detect_loop(struct node* href)
{
    struct node *slow=href,*fast=href;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return 1;
    }
    return 0;
}
int main()
{
    struct node * head=NULL;
    push(&head,40);
    push(&head,50);
    push(&head,60);
    push(&head,80);
    push(&head,90);
    push(&head,100);
    head->next->next->next->next->next->next=head;
    int result=detect_loop(head);
    if(result==0)
        printf("loop not found");
    else
        printf("loop found");
    return 0;

}


