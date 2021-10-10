#include <stdio.h>

void mapArray(int arrayOneD[],int n,int m)
{
    int arrayTwoD[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arrayTwoD[i][j] = arrayOneD[(i * m) + j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", arrayTwoD[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Enter the values of n and m: ");
    scanf("%d %d", &n, &m);

    int arrayOneD[n * m];
    for (int i = 0; i < n * m; i++)
        scanf("%d", &arrayOneD[i]);
    mapArray(arrayOneD, n, m);
    return 0;
}