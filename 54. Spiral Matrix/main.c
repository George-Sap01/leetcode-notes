#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int matrixColSize, int* returnSize) {
    
    int n = matrixSize;
    int m = matrixColSize;
    int *result = (int*)malloc(sizeof(int) * n * m);
    *returnSize = n * m;

    int result_index = 0;
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = matrixColSize - 1;
    // top to bottom , left to right , bottom to top and right to left .

    int sideways = 1;
    int i;


    while(top <= bottom && left <= right)
    {
            

    }

    // Traverse the top row from left to right (from column b to tr), then increment t (move top boundary down).

    // Traverse the right column from top to bottom (from row t to br), then decrement tr (move right boundary left).

    // If t <= br, traverse the bottom row from right to left (from column tr to b), then decrement br (move bottom boundary up).

    // If b <= tr, traverse the left column from bottom to top (from row br to t), then increment b (move left boundary right).

    // Termination Condition:

    // The loop continues as long as the top boundary is less than or equal to the bottom (t <= br) 
    // and the left boundary is less than or equal to the right (b <= tr).    

    return result;
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