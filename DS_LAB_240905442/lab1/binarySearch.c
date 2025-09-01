#include <stdio.h>
int main()
{
    int n, key, i, flag = 0;
    printf("enter size of array 'n':\n");
    scanf("%d", &n);
    int a[n];
    int start = 0, end = n-1, mid = (start + end)/2;
    printf("enter %d ascending sorted elements in the array:\n", n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    printf("enter key to search for:\n");
    scanf("%d", &key);

    while(start != end)
    {
        if(a[mid] == key)
        {
            flag = 1;
            break;
        }
        else if(a[mid] > key)
        {
            end = mid - 1;
            mid = (end + start)/2;
        }
        else
        {
            start = mid + 1;
            mid = (start + end)/2;
        }
    }

    if(a[mid] == key)
    {
        flag = 1;
    }

    if(flag == 1)
        printf("element matching key found.\nlocation index: %d", mid);
    else
        printf("element matching key not found.");

    return 0;
}
