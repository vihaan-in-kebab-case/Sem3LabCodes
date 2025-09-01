#include<stdlib.h>
#include<stdio.h>
int smallest(int *p, int s)
{
    int i, min = *p;
    for(i=0 ; i<s ; i++)
    {
        if(*p < min)
            min = *p;
        p++;
    }
    return min;
}

int main()
{
    int *a;
    int i, n;
    printf("enter number of elements:\n");
    scanf("%d", &n);

    a = (int *)malloc(n*sizeof(int));
    if(a == NULL)
    {
        printf("memory not allocated.");
        return -1;
    }

    printf("enter %d elements:\n", n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    printf("smallest element in array is: %d", smallest(&a[0], n));
    free(a);
    return 0;
}
