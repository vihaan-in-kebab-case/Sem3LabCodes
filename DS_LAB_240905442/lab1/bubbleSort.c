#include <stdio.h>
int main()
{
    int n, i, j, temp, choice;
    printf("enter size of array 'n':\n");
    scanf("%d", &n);
    int a[n];
    printf("enter %d elements in the array:\n", n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);

    printf("enter '1' for ascending sort and '2' for descending sort:\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            for(i=0 ; i<n-1 ; i++)
            {
                for(j=0 ; j<n-i-1 ; j++)
                {
                    if(a[j] > a[j+1])
                    {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
        }
        break;

        case 2:
        {
            for(i=0 ; i<n-1 ; i++)
            {
                for(j=0 ; j<n-i-1 ; j++)
                {
                    if(a[j] < a[j+1])
                    {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
        }
        break;

        default: printf("invalid choice entered");
    }

    if(choice == 1 || choice == 2)
    {
        printf("sorted array:\n");
        for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);
    }

    return 0;
}
