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

int* findDiagonalOrder(int** mat, int matSize, int matColSize, int* returnSize)
{
    int m = matSize;
    int n = matColSize;
    int *result = (int*)malloc(m * n * sizeof(int));
    int k = 0;  // index for the result array

    // s -> sum of indexes for each diagonal 

    for (int s = 0; s < m + n - 1; s++)
    {
        int r = (s < m) ? s : m - 1; // r = row
        /*
            if s < m
                r = s
            else
                r = m - 1
        */
        int c = s - r; // c = col

        if (s % 2 == 0)
        {
            while (r >= 0 && c < n)
            {
                result[k] = mat[r][c];
                k++;
                r--;
                c++;
            }
        }
        else
        {
            r = (s < n) ? 0 : s - n + 1;
            /*
                if s < n
                    r = 0
                else
                    r = s - n + 1
            */
            c = s - r;

            while (r < m && c >= 0)
            {
                result[k] = mat[r][c];
                k++;
                r++;
                c--;
            }
        }
    }

    *returnSize = k;
    return result;
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

    
    ret = findDiagonalOrder(arr, n, m, &retlen);

    for(int i = 0; i<retlen; i++)
        printf("%d ", ret[i]);

    return 0;
}