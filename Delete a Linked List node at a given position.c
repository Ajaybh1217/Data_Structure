#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
void deleteafterposition(struct node **href ,int pos)
{
    struct node *prev;
    struct node *temp=*href;
    int i=0;
    if(pos==0&&temp!=NULL)
    {
        *href=temp->next;
        free(temp);
        return;
    }
    while(i<pos&&temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
        i=i+1;
    }
    if(temp==NULL)
    {
        printf("position not exit");
        return;
    }
    prev->next=temp->next;
    free(temp);

}

void printlist(struct node * n)
{
    while(n!='\0')
    {
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}
void push(struct node **href,int data)
{
    struct node *ptr=*href;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=ptr;
    *href=newnode;
}
int main()
{
    struct node *head=NULL;
    push(&head,17);
    push(&head,18);
    push(&head,19);
    push(&head,20);
    printlist(head);
    deleteafterposition(&head,3);
    printlist(head);
}
