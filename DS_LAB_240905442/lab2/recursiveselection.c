#include <stdio.h>
int *findMin(int *p, int *min, int s, int ctr)
{
    if(ctr == s)
        return min;
    else
    {
        if(*p < *min)
            min = p;
        return findMin(p+1, min, s, ctr+1);
    }
}

void sort(int *p, int s, int ctr)
{
    int temp, *min;
    if(ctr == s-1)
        return;
    else
    {
        min = findMin(p+1, p, s, ctr+1);
        if(min != p)
        {
            temp = *min;
            *min = *p;
            *p = temp;
        }
        return sort(p+1, s, ctr+1);
    }
}

int main()
{
    int i, n;
    printf("enter number of elements:\n");
    scanf("%d", &n);
    int a[n];
    printf("enter %d elements:\n", n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    printf("unsorted array: ");
    for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);

    sort(&a[0], n, 0);

    printf("\nsorted array: ");
    for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);

    return 0;
}
