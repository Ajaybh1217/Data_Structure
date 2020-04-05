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
void removeduplicate(struct node** head)
{
    int k=0;
    struct node *current=*head;
    struct node *ptr,*curr_ent;
    struct node *next_node=current->next;
    while(next_node!=NULL)
    {
        if(current->data==next_node->data)
        {
            ptr=next_node;
            current->next=ptr->next;
            free(ptr);
        }
        else
        {
            if(k==0)
            curr_ent=current;
            current=current->next;
            k=1;

        }
        next_node=next_node->next;
    }
    *head=curr_ent;

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
void removeDuplicates(struct node * head)
{
    /* Pointer to traverse the linked list */
   struct node* current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
    return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
    /* Compare current node with next node */
    if (current->data == current->next->data)
    {
        /* The sequence of steps is important*/
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
    }
    else /* This is tricky: only advance if no deletion */
    {
        current = current->next;
    }
    }
}

int main()
{
    struct node* head=NULL;
    push(&head,10);
    push(&head,10);
    push(&head,56);
    push(&head,56);
    push(&head,65);
    push(&head,65);
    push(&head,77);
    //removeduplicate(&head);
   // removeDuplicates( head);
    printlist(head);
}

