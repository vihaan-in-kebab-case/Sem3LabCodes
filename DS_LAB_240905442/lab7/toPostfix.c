#include <stdlib.h>
#include <stdio.h>

#define cap 100
typedef struct stackElement
{
    char data;
    struct stackElement* next;
}ele;

ele* top = NULL;

int isOperand()
{

}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '/' || op == '*' || op == '%')
        return 2;
    else if(op == '^')
        return 3;
    return 0;
}

int hasHigherOrEqualPrecedence(char stack, char exp)
{
    
}

int main()
{
    return 0;
}