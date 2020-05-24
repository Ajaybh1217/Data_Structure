#include<stdio.h>
int front=0,rear=0;
int  n=6;
int  q[6];
void enqueue(int);
int  dequeue();
int main()
{
    int item=0,i;
    for(i=0;i<5;i++)
    {
      scanf("%d",&item);
      enqueue(item);

    }
    printq(q);
    printf("\n");
    int item_deleted=dequeue();
    printf("delted item=%d",item_deleted);

}

void enqueue(int item)
{
    rear=(rear+1)%n;
    if(rear==front)
    {
        printf("overflow");
        if(rear==0)
            rear=n-1;
        else
            rear=rear-1;
    }
    else
    {
        q[rear]=item;

    }


}
int dequeue()
{
    if(front==rear)
        printf("underflow");
    front=(front+1)%n;
    return q[front];
}

void printq(int q[])
{
    int f=front+1,r=rear+1%n;
    if(front!=rear)
    {
        while(f!=r)
        {
            printf("\n%d",q[f]);
            f=f+1;
        }
    }
    else
        {printf("there is no element");}

}
