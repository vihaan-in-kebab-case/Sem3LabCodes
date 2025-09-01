#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, l, m, n, p, q, tempsum=0;
    printf("enter rows and columns of matrix a:\n");
    scanf("%d%d", &m, &n);

    printf("enter rows and columns of matrix b:\n");
    scanf("%d%d", &p, &q);

    if(n==p)
    {
        int** a = (int**)malloc(m * sizeof(int*));
        for (i = 0; i < m; i++)
            a[i] = (int*)malloc(n * sizeof(int));

        int** b = (int**)malloc(p * sizeof(int*));
        for (i = 0; i < p; i++)
            b[i] = (int*)malloc(q * sizeof(int));

        int** product = (int**)malloc(m * sizeof(int*));
        for (i = 0; i < m; i++)
            product[i] = (int*)malloc(q * sizeof(int));

        printf("enter %dx%d elements in matrix a:\n", m, n);
        for(i=0 ; i<m ; i++)
            for(j=0 ; j<n ; j++)
                scanf("%d", (*(a + i) + j));

        printf("enter %dx%d elements in matrix b:\n", p, q);
        for(i=0 ; i<p ; i++)
            for(j=0 ; j<q ; j++)
                scanf("%d", (*(b + i) + j));

        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<q ; j++)
            {
                tempsum = 0;
                for(k=0 ; k<n ; k++)
                {
                    tempsum += *(*(a + i) + k) * *(*(b + k) + j);
                }
                *(*(product + i) + j) = tempsum;
            }
        }

        printf("matrix a:\n");
        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
                printf("%d\t", *(*(a + i) + j));
            printf("\n");
        }

        printf("matrix b:\n");
        for(i=0 ; i<p ; i++)
        {
            for(j=0 ; j<q; j++)
                printf("%d\t", *(*(b + i) + j));
            printf("\n");
        }

        printf("product matrix:\n");
        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<q ; j++)
                printf("%d\t", *(*(product + i) + j));
            printf("\n");
        }

        free(a);
        free(b);
        free(product);
    }
    else
        printf("matrix multiplication not possible");

    return 0;
}
