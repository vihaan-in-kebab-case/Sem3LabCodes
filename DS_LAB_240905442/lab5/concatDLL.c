#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = d;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

node* x1 = NULL;
node* t1 = NULL;

node* x2 = NULL;
node* t2 = NULL;

void insertRearX1(int d)
{
    node* nn = createNode(d);
    if(x1==NULL)
    {
        x1=nn;
        t1=nn;
    }

    else
    {
        if(x1 == t1)
        {
            x1->next = nn;
            nn->prev = x1;
        }
        t1 -> next = nn;
        nn -> prev = t1;
        t1 = nn;
    }
    nn = NULL;
    printf("element successfully inserted at rear end\n");
}

void insertRearX2(int d)
{
    node* nn = createNode(d);
    if(x2==NULL)
    {
        x2=nn;
        t2=nn;
    }

    else
    {
        if(x2 == t2)
        {
            x2->next = nn;
            nn->prev = x2;
        }
        t2 -> next = nn;
        nn -> prev = t2;
        t2 = nn;
    }
    nn = NULL;
    printf("element successfully inserted at rear end\n");
}

void concatLists()
{
    t1 -> next = x2;
    x2 -> prev = t1;
    t1 = t2;
    x2 = NULL;
    t2 = NULL;
}

int main()
{
    int ch, cnt = 1, td;
    do
    {
        printf("enter choice:\n1. insert element at end of X1\n2. insert element at end of X2\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:  printf("enter data to insert at end of list:\n");
                     scanf("%d", &td);
                     insertRearX1(td);
            break;

            case 2: printf("enter data to insert at end of list:\n");
                    scanf("%d", &td);
                    insertRearX2(td);
            break;

            default: printf("invalid input!\n");
        }

        printf("enter 1 to continue and 0 to stop\n");
        scanf("%d", &cnt);
    } while (cnt != 0);

    concatLists();
    printf("NULL <-> ");

    node* cur = x1;
    while(cur != NULL)
    {
        printf("%d <-> ", cur -> data);
        cur = cur -> next;
    }
    printf("NULL\n");
    
    return 0;
}