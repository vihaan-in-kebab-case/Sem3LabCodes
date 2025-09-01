#include <stdio.h>
int main()
{
    int n, i, key, flag = 0;
    printf("enter size of array 'n':\n");
    scanf("%d", &n);
    int a[n];
    printf("enter %d elements in the array:\n", n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    printf("enter key to search for:\n");
    scanf("%d", &key);

    for(i=0 ; i<n ; i++)
        if(a[i] == key)
        {
            flag = 1;
            break;
        }

    if(flag == 1)
        printf("element matching key found.\nlocation index: %d", i);
    else
        printf("element matching key not found.");

    return 0;
}
