#include <stdio.h>
#include <stdlib.h>

#define cap 100
typedef struct stack
{
    char stck[cap];
    int top;
}stack;

stack openingParantheses;

int isEmpty()
{
    if(openingParantheses.top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if(openingParantheses.top == cap-1)
        return 1;
    return 0;
}

void push(char item)
{
    if(isFull())
    {
        printf("stack is full.\n");
        return;
    }

    else
        openingParantheses.stck[++openingParantheses.top] = item;
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
        char ele = openingParantheses.stck[openingParantheses.top];
        openingParantheses.top--;
        return ele;
    }
}

int checkPair(char open, char close)
{
    if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
        return 1;
    return 0;
}

int checkBalanced(char* exp)
{
    while((*exp) != '\0')
    {
        if(((*exp) == '(') || ((*exp) == '{') || ((*exp) == '['))
        {
            push((*exp));
        }

        else if(((*exp) == ')') || ((*exp) == '}') || ((*exp) == ']'))
        {
            if(isEmpty())
                return 0;
            
            else 
            {
                char temp = pop();
                if(checkPair(temp, (*exp)) == 0)
                    return 0;
            }
        }
        exp++;
    }

    if(isEmpty())
        return 1;
    return 0;
}

int main()
{
    char expression[100];
    printf("enter expression with parantheses:\n");
    scanf("%s", expression);
    openingParantheses.top = -1;

    if(checkBalanced(expression) == 1)
        printf("parantheses are balanced\n");

    else
        printf("parantheses are not balanced\n");
}