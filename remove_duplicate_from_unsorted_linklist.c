#include<stdio.h>
#include<stdlib.h>
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
void removeduplicate_unsortedlist(struct node* head)
{
    struct node *current=head;
    struct node * next_node,*temp;
    while(current->next!=NULL)
    {
        next_node=current->next;
        temp=current;
        while(next_node!=NULL)
        {

            if(current->data==next_node->data)
            {
                temp->next=next_node->next;
                free(next_node);
                next_node=temp->next;
            }
            else
            {
                 temp=next_node;
                 next_node=next_node->next;
            }
        }
        current=current->next;
    }

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
int main()
{
    struct node* head=NULL;
    push(&head,56);
    push(&head,10);
    push(&head,56);
    push(&head,56);
    push(&head,65);
    push(&head,65);
    push(&head,77);
   removeduplicate_unsortedlist(head);

    printlist(head);
}


