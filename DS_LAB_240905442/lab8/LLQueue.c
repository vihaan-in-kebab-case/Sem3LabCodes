#include <stdio.h>
#include <stdlib.h>
typedef struct SLL
{
    int ele;
    struct SLL* next;
}SLL;

SLL* front = NULL;
SLL* rear = NULL;

void enqueue(int ele)
{
    SLL* nn = (SLL*)malloc(sizeof(SLL));
    nn -> ele = ele;
    nn -> next = NULL;

    if(front == NULL)
        front = nn;

    if(rear != NULL)
        rear -> next = nn;
    rear = nn;
}

int dequeue()
{
    if(front == NULL)
    {
        printf("queue is empty\n");
        return -9999;
    }

    else
    {
        if(front == rear)
        {
            int tempEle = rear -> ele;
            printf("element dequeued: %d\n", tempEle);
            front = rear = NULL;
            return tempEle;
        }

        else
        {
            int tempEle = front -> ele;
            printf("element dequeued: %d\n", tempEle);
            front = front -> next;
            return tempEle;
        }
    }
}

void display()
{
    printf("elements in queue:\n");
    if(front == NULL)
        printf("queue is empty\n");
        
    SLL* temp = front;
    while(temp != NULL)
    {
        printf("%d\n", temp -> ele);
        temp = temp -> next;
    }
}

int main()
{
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
