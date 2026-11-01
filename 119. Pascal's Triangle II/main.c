#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;

    if(rowIndex == 0) {
        result[0] = 1;
        return result;
    }

    result[0] = 1;
    result[1] = 1;

    if(rowIndex == 1) return result;

    int j, i;
    int prev_right;
    int prev_left;
    for(i = 1; i < rowIndex; i++)
    {   
        prev_left = result[0];
        prev_right = result[1];
        for(j = 1; j < i+1; j++) {
            result[j] = prev_left + prev_right;
            prev_left = prev_right;
            prev_right = result[j+1];
        }
        result[i+1] = 1;
    }


    return result;
}

int main()
{
    int resultlen;
    int rowindex = 6;

    int *result;

    result = getRow(rowindex, &resultlen);

    for(int i = 0; i < resultlen; i++)
        printf("%d ", result[i]);


    return 0;
}