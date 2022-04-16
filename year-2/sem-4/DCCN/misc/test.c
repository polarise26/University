#include <stdio.h>

int main()
{
    int i, j, A[10][10], B[10][10], n = 3;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", A[i][j]);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            B[i][j] = A[j][i];

    for (i = 0; i < n; ++i)
    {
        printf("\n");
        for (j = 0; j < n; ++j)
            printf("%d ", B[i][j]);
    }
    return 0;
}