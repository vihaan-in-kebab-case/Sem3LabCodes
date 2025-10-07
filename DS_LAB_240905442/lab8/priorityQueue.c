#include <stdio.h>
#include <stdlib.h>
typedef struct patients
{
    char name[50];
    int age;
    int priority;
    struct patients* next;
}patients;

patients* front = NULL;
patients* rear = NULL;

void enqueue(char n[], int a, int p)
{
    patients* nn = (patients*)malloc(sizeof(patients));
    strcpy(nn -> name, n);
    nn -> age = a;
    nn -> priority = p;
    nn -> next = NULL;

    if(front == NULL)
        front = nn;

    if(rear != NULL)
        rear -> next = nn;
    rear = nn;
}

void dequeue()
{
    if(front == NULL)
    {
        printf("queue is empty\n");
        return;
    }

    else
    {
        if(front == rear)
        {
            printf("patient dequeued:\n");
            printf("name: %s\n", front -> name);
            printf("age: %d\n", front -> age);
            printf("priority: %d\n", front -> priority);
            patients* temp = front;
            front = rear = NULL;
            free(temp);
        }
            
        else
        {
            patients* cur = front -> next;
            patients* maxP = front -> priority;
            while(cur -> next != NULL)
            {
                if(cur -> next -> priority > maxP -> priority)
                    maxP = cur;
                cur = cur -> next;
            }

            if(maxP == front)
            {
                printf("patient dequeued:\n");
                printf("name: %s\n", front -> name);
                printf("age: %d\n", front -> age);
                printf("priority: %d\n", front -> priority);

                patients* temp = front;
                front = front -> next;
                free(temp);
            }

            else
            {
                printf("patient dequeued:\n");
                printf("name: %s\n", maxP -> next -> name);
                printf("age: %d\n", maxP -> next -> age);
                printf("priority: %d\n", maxP -> next -> priority);

                patients* temp = maxP -> next;
                maxP -> next = maxP -> next -> next;
                free(temp);
            }
        }
    }
}

void display()
{
    printf("elements in queue:\n");
    if(front == NULL)
        printf("queue is empty\n");
        
    patients* temp = front;
    while(temp != NULL)
    {
        printf("Name: %s\n", temp -> name);
        printf("Age: %d\n", temp -> age);
        printf("Priority %d\n", temp -> priority);
        temp = temp -> next;
    }
}

int main()
{
    int cnt = 1, ch;
    char name[50];
    int age, priority;
    do
    {
        printf("enter choice:\n1. queue a patient\n2. dequeue a patient based on priority\n3. display all queued patients\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: int i;
                    printf("enter name, age and priority of patient to queue\n");
                    scanf("%s", name);
                    scanf("%d", &age);
                    scanf("%d", &priority);
                    enqueue(name, age, priority);
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
