#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define cap 100
typedef struct task
{
    int docID;
    char name[50]
}task;

task tasks[cap];
int front, rear;

void enqueue(int d, char n[])
{
    if(rear == cap - 1)
    {
        printf("queue is full\n");
        return;
    }

    if(front == -1)
        front = 0;
   
    tasks[++rear].docID = d;
    strcpy(tasks[rear].name, n);
    printf("print job %d queued successfully...\n", tasks[rear].docID);
}

void dequeue()
{
    if(front == -1)
    {
        printf("queue is empty\n");
        return;
    }

    else if(front == rear)
    {
        printf("print job started...\nDocument ID: %d\nDocument Name: %s\n", tasks[rear].docID, tasks[front].name);
        front = rear = -1;       
    }

    else
    {
        printf("print job started...\nDocument ID: %d\nDocument Name: %s\n", tasks[front].docID, tasks[front].name);
        front++;
    }
}

void display()
{
    printf("printer queue:\n");
    if(front == -1)
    {
        printf("queue is empty.\n");
        return;
    }

    else
    {
        int temp = front;
        while(temp <= rear)
        {
            printf("task %d:\nDocument ID: %d\nDocument Name: %s\n\n", temp, tasks[temp].docID, tasks[temp].name);
            temp++;
        }
    }
}

int main()
{
    front = rear = -1;
    int cnt = 1, ch;
    do
    {
        printf("enter choice:\n1. queue a print job\n2. start a print job\n3. display active print jobs\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: int i;
                    char n[50];
                    printf("enter doc id and name\n");
                    scanf("%d", &i);
                    scanf("%s", n);
                    enqueue(i, n);
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