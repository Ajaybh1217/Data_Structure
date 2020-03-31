#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void printlist(struct node** n)
{
    while((*n)!='\0')
    {
        printf("%d ",(*n)->data);
        //(*n)->data=20;
        (*n)=(*n)->next;
    }
}
int main()
{
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=5;
    head->next=second;
    second->data=10;
    second->next=third;
    third->data=15;
    third->next=NULL;
    printlist(&head);

}
