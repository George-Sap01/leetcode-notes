#include <stdio.h>
#include <stdlib.h>


/*  a = 4x3

    [0, 0] [0, 1] [0, 2]
    [1, 0] [1, 1] [1, 2]
    [2, 0] [2, 1] [2, 2]
    [3, 0] [3, 1] [3, 2]

    => 
    [0, 0] || [0, 1] [1, 0] || [0, 2] [1, 1] [2, 0] || [1, 2] [2, 1] [3, 0] || [2, 2] [3, 1] || [3, 2]   
*/
int* findDiagonalOrder(int** mat, int matSize, int matColSize, int* returnSize) {
    
    int *ret = (int*)malloc(sizeof(int) * (matSize * matColSize));
    *returnSize = matSize * matColSize;

    int threshold = matSize - 1 + matColSize - 1; // the indexes of the last element in the right down corner
    int up = 1;
    int index_sum;
    int ret_index = 1;

    for(index_sum = 1; index_sum < threshold; index_sum++)
    {    
        if(up == 0)
        {
            for(int i = 0; i < matSize; i++) {
                for(int j = 0; j < matColSize; j++) {
                    if(i + j == index_sum) {
                        ret[ret_index] = mat[i][j];
                        ret_index++;
                    }    
                }
                if( i > index_sum)
                    break;
            }
            up = 1;
        }
        else
        {
            for(int i = matSize-1; i > -1; i--) {
                for(int j = 0; j < matColSize; j++) {
                    if(i + j == index_sum) {
                        ret[ret_index] = mat[i][j];
                        ret_index++;
                    }
                }
            }
            up = 0;
        }
    }

    ret[0]= mat[0][0];
    ret[(matSize * matColSize) - 1] = mat[matSize-1][matColSize - 1];
    return ret;
}

int main()
{
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    int **arr = (int**)malloc(sizeof(int*)* n);

    for(int i = 0; i < n; i++)
        arr[i] = (int*)malloc(sizeof(int) * m);


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = a[i][j];

    int *ret;
    int retlen;

    
    ret = findDiagonalOrder2(arr, n, m, &retlen);

    for(int i = 0; i<retlen; i++)
        printf("%d ", ret[i]);

    return 0;
}