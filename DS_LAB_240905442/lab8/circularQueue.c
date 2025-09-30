#include <stdio.h>
#include <stdlib.h>
#define cap 5
typedef struct circular
{
    int cq[cap];
    int front, rear;
}circular;

circular CQ;

int isEmpty()
{ 
    if(CQ.front == -1)
        return 1;
    return 0;
}

int isFull()
{
    if((CQ.rear+1) % cap == CQ.front)
        return 1;
    return 0;
}

void enqueue(int ele)
{
    if(isFull())
    {
        printf("queue is full\n");
        return;
    }

    else
    {
        if(CQ.front == -1)
            CQ.front = 0;

        CQ.cq[(CQ.rear + 1) % cap] = ele;
        CQ.rear = (CQ.rear + 1) % cap;
        printf("element inserted successfully\n"); 
    }
}

int dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        return;
    }

    else
    {
        if(CQ.front == CQ.rear)
        {
            int tempEle = CQ.cq[CQ.rear];
            CQ.front = CQ.rear = -1;
            printf("element dequeued: %d\n", tempEle);
            return tempEle;
        }

        else
        {
            int tempEle = CQ.cq[CQ.front];
            CQ.front = (CQ.front + 1) % cap;
            printf("element dequeued: %d\n", tempEle);
            return tempEle;
        }
    }
}

void display()
{
    printf("elements in queue:\n");
    if(CQ.front == -1)
    {
        printf("queue is empty.\n");
        return;
    }

    else
    {
        int temp = CQ.front;
        while(temp != CQ.rear)
        {
            printf("%d\n", CQ.cq[temp]);
            temp = (temp + 1) % cap;
        }
        printf("%d\n", CQ.cq[CQ.rear]);
    }
}

int main()
{
    CQ.front = CQ.rear = -1;
    int cnt = 1, ch;
    do
    {
        printf("enter choice:\n1. queue an element\n2. dequeue an element\n3. display all queue elements\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: int i;
                    printf("enter element to queue\n");
                    scanf("%d", &i);
                    enqueue(i);
            break;

            case 2: dequeue();
            break;

            case 3: display();
            break;

            default: printf("invalid choice entered\n");
        }
        printf("enter 1 to continue and 0 to exit\n");
        scanf("%d", &cnt);
    } while (cnt != 0);
    return 0;
}