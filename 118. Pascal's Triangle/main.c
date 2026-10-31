#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    *returnSize = numRows; // number of individual arrays.
    // *returnColumnSizes -> an array that holds the numbers of columns for each row.

    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; i++)
        (*returnColumnSizes)[i] = i+1;

    int **mat = (int**)malloc(sizeof(int*) * numRows);
    for(int i = 0; i < numRows; i++)
        mat[i] = (int*)malloc(sizeof(int) * (*returnColumnSizes)[i]);

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < (*returnColumnSizes)[i]; j++)
        {
            if(j == 0 || j == (*returnColumnSizes)[i]-1)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        }
            
    }

    return mat;
}

int main()
{
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    int **arr = (int**)malloc(sizeof(int*)* n);


    int **mat;
    int size;
    int *colSizes;
    int numrows = 5;

    mat = generate(numrows, &size, &colSizes);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < colSizes[i]; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}