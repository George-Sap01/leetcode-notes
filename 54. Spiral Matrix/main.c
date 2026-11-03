#include <stdio.h>
#include <stdlib.h>

/*


    1  2  3 
    4  5  6
    7  8  9
    10 11 12


*/


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;

    int total = matrixSize * matrixColSize[0];
    int* spiral = (int*)malloc(sizeof(int) * total);
    int idx = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            spiral[idx++] = matrix[top][i];
        top++;

        for (int j = top; j <= bottom; j++)
            spiral[idx++] = matrix[j][right];
        right--;

        if (top <= bottom) {
            for (int k = right; k >= left; k--)
                spiral[idx++] = matrix[bottom][k];
            bottom--;
        }

        if (left <= right) {
            for (int l = bottom; l >= top; l--)
                spiral[idx++] = matrix[l][left];
            left++;
        }
    }

    *returnSize = idx;
    return spiral;
}


int main()
{
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    int **arr = (int**)malloc(sizeof(int*)* n);


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\n");
    for(int i = 0; i < n; i++)
        arr[i] = (int*)malloc(sizeof(int) * m);


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = a[i][j];

    int *result;
    int retlen;

    result = spiralOrder(arr, n, m, &retlen);

    for(int i = 0; i < retlen; i++)
        printf("%d ", result[i]);

    return 0;
}