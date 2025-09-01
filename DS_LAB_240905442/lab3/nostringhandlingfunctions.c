#include <stdio.h>
#include <stdlib.h>
int findLength(char *p)
{
    int len = 0;
    while(*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

void concatenate(char *s1, char *s2)
{
    while(*s1 != '\0')
        s1++;

    while(*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
}

int stringCompare(char *s1, char *s2)
{
    int comparison, flag = 0;
    while(*s2 != '\0' && *s1 != '\0')
    {
        if(*s2 != *s1)
        {
            flag = 1;
            comparison = (int)*s1 - (int)*s2;
            break;
        }
        s1++;
        s2++;
    }

    if(flag == 0)
    {
        if(findLength(s1) == findLength(s2))
            comparison = 0;

        else
            comparison = findLength(s1) - findLength(s2);
    }
    return comparison;
}

void insertSub(char *s, char *sub, int pos)
{
    int subLen = findLength(sub), i, strinLen = findLength(s);
    if(pos > strinLen)
    {
        printf("invalid position\n");
        return;
    }

    for(i=1 ; ; i++)
    {
        s++;
        if(*s == '\0')
            break;
    }
    s=s-1;

    for(i=0 ; i<(strinLen - pos) ; i++)
    {
        *(s+subLen) = *s;
        s--;
    }
    s=s+1;

    for(i=0 ; i<subLen ; i++)
    {
        *s = *sub;
        s++;
        sub++;
    }
}

void deleteSub(char *s, char *sub)
{
    int flag = 0, i, subLen = findLength(sub), strLen = findLength(s), j, ctr=0, temp;
    for(i=1 ; i<= strLen-subLen + 1 ; i++)
    {
        ctr = 0;
        flag = 0;
        if(*s == *sub)
        {
            flag = 1;
            for(j=0 ; j<subLen ; j++)
            {
                if(*s != *sub)
                {
                    flag = 0;
                    break;
                }
                s++;
                sub++;
                ctr++;
            }

            if(flag == 1)
                break;

            else
            {
                s = s-ctr;
                sub = sub-ctr;
            }
        }

        else 
            s++;
    }
    temp = i-1;

    if(flag == 1)
    {
        s = s-ctr;
        for(i=0 ; i<strLen - (subLen + temp - 1) ; i++)
        {
            *s = *(s+subLen);
            s++;
        }
        for(i=0 ; i<strLen - (subLen + temp - 1) ; i++)
            *s = '\0';
    }
    
    else
        printf("substring not found\n");
}

int main()
{
    printf("%d\n", findLength("yourmom"));

    char sa[500] = "your";
    char sb[500] = "mom";
    concatenate(sa, sb);
    printf("%s\n", sa);

    char san[500] = "your";
    printf("%d\n", stringCompare("yourmom", "your"));

    char subsins[500] = "suck";
    insertSub(subsins, "some", 4);
    printf("%s\n", subsins);

    char subdel[500] = "yourmom";
    deleteSub(subdel, "ur");
    printf("%s\n", subdel);
    return 0;
}
