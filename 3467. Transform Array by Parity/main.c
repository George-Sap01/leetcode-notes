#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] % 2 == 0)
        {
            result[left] = 0;
            left++;
        }
        else
        {
            result[right] = 1;
            right--;
        }
    }
    return result; 
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = LEN(arr);
    int *res;
    int reslen;

    res = transformArray(arr, len, &reslen);
    for(int i = 0; i <reslen; i++)
        printf("%d ", res[i]);

    return 0;
}