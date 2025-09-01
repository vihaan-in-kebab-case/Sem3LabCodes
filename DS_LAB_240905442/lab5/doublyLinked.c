#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int d);
void insertRear(int d);
void deleteRear();
void insertBetween(int pos, int d);
void deleteBetween(int pos);
void insertAfter(int cd, int d);
void insertBefore(int cd, int d);
void forwardTraversal();
void reverseTraversal();

node* head = NULL;
node* tail = NULL;

int main()
{
    int ch, td, tpos, tcd, cont = 1;
    do
    {
        printf("enter your choice:\n1. Insert element at rear end\n2. Delete element from rear end\n3. Insert element at specific position\n4. Delete element from specific position\n5. Insert element after node containing a specific value\n6. Insert element before node containing a specific value\n7. Traverse Forward\n8. Traverse Backward\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("enter data to insert at end of list:\n");
            scanf("%d", &td);
            insertRear(td);
            break;

        case 2:
            deleteRear();
            break;

        case 3:
            printf("enter position to insert data in:\n");
            scanf("%d", &tpos);
            printf("enter data to insert in entered position:\n");
            scanf("%d", &td);
            insertBetween(tpos, td);
            break;

        case 4:
            printf("enter position to delete data from:\n");
            scanf("%d", &tpos);
            deleteBetween(tpos);
            break;

        case 5:
            printf("enter value of data present in existing node to insert new data after it:\n");
            scanf("%d", &tcd);
            printf("enter new data to be inserted:\n");
            scanf("%d", &td);
            insertAfter(tcd, td);
            break;

        case 6:
            printf("enter value of data present in existing node to insert new data before it:\n");
            scanf("%d", &tcd);
            printf("enter new data to be inserted:\n");
            scanf("%d", &td);
            insertBefore(tcd, td);
            break;

        case 7:
            printf("traversing in forward direction:\n");
            forwardTraversal();
            break;

        case 8:
            printf("traversing in reverse direction:\n");
            reverseTraversal();
            break;

        default:
            printf("invalid choice entered!\n");
        }

        printf("enter 1 to continue and 0 to stop.\n");
        scanf("%d", &cont);
    }
    while(cont != 0);
    printf("exited successfully\n");

    return 0;
}

node* createNode(int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = d;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void insertRear(int d)
{
    node* nn = createNode(d);
    if(head==NULL)
    {
        head=nn;
        tail=nn;
    }

    else
    {
        if(head == tail)
        {
            head->next = nn;
            nn->prev = head;
        }
        tail -> next = nn;
        nn -> prev = tail;
        tail = nn;
    }
    nn = NULL;
    printf("element successfully inserted at rear end\n");
}

void deleteRear()
{
    if(head==NULL)
    {
        printf("list is empty, cannot delete\n");
    }

    else
    {
        node* temp = tail;
        if(head==tail)
        {
            tail = NULL;
            head = NULL;
        }

        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        free(temp);
        printf("element successfully deleted from rear end\n");
    }
}

void insertBetween(int pos, int d)
{
    if(pos < 1)
    {
        printf("invalid position entered\n");
        return;
    }

    if(pos == 1)
    {
        if(head==NULL)
        {
            insertRear(d);
            return;
        }

        else
        {
            node* tnn = createNode(d);
            head->prev = tnn;
            tnn->next = head;
            head = tnn;
        }
    }

    else
    {
        int i;
        node* nn = createNode(d);
        node* curr = head;
        for(i=1 ; i<pos-1 ; i++)
        {
            if(curr == NULL)
            {
                printf("not enough nodes in the list\n");
                return;
            }
            curr = curr->next;
        }

        if(curr == tail)
            insertRear(d);

        else
        {
            nn->next = curr->next;
            curr->next->prev = nn;
            curr->next = nn;
            nn->prev = curr;
        }
    }
}

void deleteBetween(int pos)
{
    if(pos<1)
    {
        printf("invalid position entered\n");
        return;
    }

    if(head==NULL)
    {
        printf("list is empty, no node to delete\n");
        return;
    }

    if(pos == 1)
    {
        if(head==tail)
        {
            deleteRear();
            return;
        }

        else
        {
            node* temp = head;
            head->next->prev = NULL;
            head = head->next;
            free(temp);
        }
    }

    else
    {
        int i;
        node* curr = head;
        for(i=1 ; i<pos-1 ; i++)
        {
            if(curr == NULL)
            {
                printf("not enough nodes in the list\n");
                return;
            }
            curr = curr->next;
        }

        if(curr == tail)
            deleteRear();

        else
        {
            node* temp = curr->next;
            curr -> next = curr -> next -> next;
            curr -> next -> next -> prev = curr;
            free(temp);
        }
    }
}

void insertAfter(int cd, int d)
{
    node* nn = createNode(d);
    int flag = 0;
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    if(head==tail)
    {
        if(head -> data == cd)
        {
            head -> next = nn;
            nn -> prev = head;
            tail = nn;
        }

        else
        {
            printf("entered data not present in list\n");
            return;
        }
    }

    else
    {
        node* cur = head;
        while(cur->next != NULL)
        {
            if(cur -> data == cd)
            {
                flag = 1;
                break;
            }
            cur = cur->next;
        }

        if(flag == 1)
        {
            if(cur == tail)
            {
                cur -> next = nn;
                nn -> prev = cur;
                tail = nn;
            }

            else
            {
                cur -> next -> prev = nn;
                nn -> next = cur -> next;
                cur -> next = nn;
                nn -> prev = cur;
            }
        }

        else
        {
            printf("entered data not present in list\n");
            return;
        }
    }
    nn = NULL;
}

void insertBefore(int cd, int d)
{
    node* nn = createNode(d);
    int flag = 0;
    if(head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    if(head==tail)
    {
        if(head -> data == cd)
        {
            head -> prev = nn;
            nn -> next = head;
            head = nn;
        }

        else
        {
            printf("entered data not present in list\n");
            return;
        }
    }

    else
    {
        node* cur = head;
        while(cur->next != NULL)
        {
            if(cur -> data == cd)
            {
                flag = 1;
                break;
            }
            cur = cur->next;
        }

        if(flag == 1)
        {
            if(cur == head)
            {
                cur -> prev = nn;
                nn -> next = cur;
                head = nn;
            }

            else
            {
                cur -> prev -> next = nn;
                nn -> prev = cur -> prev;
                cur -> prev = nn;
                nn -> next = cur;
            }
        }

        else
        {
            printf("entered data not present in list\n");
            return;
        }
    }
    nn = NULL;
}

void forwardTraversal()
{
    node* curr = head;
    printf("NULL <-> ");
    while(curr != NULL)
    {
        printf("%d <-> ", curr -> data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void reverseTraversal()
{
    node* curr = tail;
    printf("NULL <-> ");
    while(curr != NULL)
    {
        printf("%d <-> ", curr -> data);
        curr = curr->prev;
    }
    printf("NULL\n");
}
