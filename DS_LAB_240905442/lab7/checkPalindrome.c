#include <stdio.h>
#include <stdlib.h>

#define cap 100
typedef struct stack
{
    char stck[cap];
    int top;
}stack;

stack rev;

void push(char item)
{
    if(isFull())
    {
        printf("stack is full.\n");
        return;
    }

    else
        rev.stck[++rev.top] = item;
}

char pop()
{
    if(isEmpty())
    {
        printf("stack is empty\n");
        return '\0';
    }

    else
    {
        char ele = rev.stck[rev.top];
        rev.top--;
        return ele;
    }
}

int isEmpty()
{
    if(rev.top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if(rev.top == cap-1)
        return 1;
    return 0;
}

int main()
{
    char sent[100];
    scanf("%s", sent);
    char* ptr = sent;
    rev.top = -1;
    int flag = 1;

    while(*ptr != '\0')
    {
        push(*ptr);
        ptr++;
    }

    ptr = sent;
    while(!isEmpty())
    {
        char curr = pop();
        if(curr != *ptr)
        {
            flag = 0;
            break;
        }
        ptr++;
    }

    if(flag == 1)
        printf("string is a palindrome\n");

    else
        printf("string is not a palindrome\n");
    
    return 0;
}