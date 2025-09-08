#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int d)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void insertRear(int td)
{
    node *nn = createNode(td);
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = nn;
    }
}

void insertBefore(int tcd, int td)
{
    int flag = 0;
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        node *nn = createNode(td);
        if (head->data == tcd)
        {
            nn->next = head;
            head = nn;
        }
        else
        {
            node *cur = head;
            while (cur->next != NULL)
            {
                if (cur->next->data == tcd)
                {
                    flag = 1;
                    break;
                }
                cur = cur->next;
            }
            if (flag == 1)
            {
                nn->next = cur->next;
                cur->next = nn;
            }

            else
            {
                printf("entered element not present in list\n");
                return;
            }
        }
    }
}

void insertAfter(int tcd, int td)
{
    int flag = 0;
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        node *nn = createNode(td);
        if (head->data == tcd)
        {
            nn->next = head->next;
            head->next = nn;
        }
        else
        {
            node *cur = head;
            while (cur != NULL)
            {
                if (cur->data == tcd)
                {
                    flag = 1;
                    break;
                }
                cur = cur->next;
            }
            if (flag == 1)
            {
                nn->next = cur->next;
                cur->next = nn;
            }

            else
            {
                printf("entered element not present in list\n");
                return;
            }
        }
    }
}

void delEle(int td)
{
    int flag = 1;
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        if (head->data == td)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            node *cur = head;
            while (cur->next != NULL)
            {
                if (cur->next->data = td)
                {
                    flag = 1;
                    break;
                }
                cur = cur->next;
            }
            if (flag == 1)
            {
                node *temp = cur->next;
                cur->next = cur->next->next;
                free(temp);
            }
            else
            {
                printf("entered data is not present in the list\n");
                return;
            }
        }
    }
}

void travDisplay()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        node *cur = head;
        while (cur != NULL)
        {
            printf("%d -> ", cur->data);
            cur = cur -> next;
        }
        printf("NULL");
    }
}

void reverseList()
{
    
}

void sortList()
{
}

void delAltNodes()
{
}

void insertMaintain(int td)
{
}

int main()
{
    int ch, td, tpos, tcd, cont = 1;
    do
    {
        printf("enter your choice:\n1. Insert Before Specified\n2. Insert After Specified\n3. Delete Element\n4. Traverse and Display\n5. Reverse SLL\n6. Sort SLL\n7. Delete every alternate node from 2 onwards\n8. Insert element in-place\n9. Insert to rear end of list\n");
        switch (ch)
        {
        case 1:
            printf("enter value of data present in existing node to insert new data before it:\n");
            scanf("%d", &tcd);
            printf("enter new data to be inserted:\n");
            scanf("%d", &td);
            insertBefore(tcd, td);
            break;

        case 2:
            printf("enter value of data present in existing node to insert new data after it:\n");
            scanf("%d", &tcd);
            printf("enter new data to be inserted:\n");
            scanf("%d", &td);
            insertAfter(tcd, td);
            break;

        case 3:
            printf("enter value of element to be deleted:\n");
            scanf("%d", &td);
            delEle(td);
            break;

        case 4:
            printf("traversing in forward direction and displaying:\n");
            travDisplay();
            break;

        case 5:
            printf("reversing the linked list:\n");
            reverseList();
            break;

        case 6:
            printf("sorting the list:\n");
            sortList();
            break;

        case 7:
            printf("deleting alternate nodes starting with 2:\n");
            delAltNodes();
            break;

        case 8:
            printf("enter data to be inserted in-place:\n");
            scanf("%d", &td);
            insertMaintain(td);
            break;

        case 9:
            printf("enter data to insert at rear end of list\n");
            scanf("%d", &td);
            insertRear(td);
            break;

        default:
            printf("invalid choice entered!\n");
        }

        printf("enter 1 to continue and 0 to stop.\n");
        scanf("%d", &cont);
    } while (cont != 0);
    printf("exited successfully\n");

    return 0;
}