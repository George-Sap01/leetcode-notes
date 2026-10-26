#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) sizeof(arr)/sizeof(int)


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
    int * result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    
    int right = *returnSize - 1, left = 0;
    int pos = *returnSize - 1;
    
    while( left < right ) {
        printf("nums[left = %d] = %d, nums[right = %d] = %d\n", left, nums[left], right, nums[right]);
        if(nums[right] * nums[right] < nums[left] * nums[left]) {
            result[pos] = nums[left] * nums[left];
            left++;            
        }
        else { 
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }
    
    result[pos] = nums[left] * nums[left];
    return result;
    
}


int main()
{   
    int arr[] = {-11, -5, -1, 0, 1, 7};
    int len = LEN(arr);

    int *ret;
    int retlen;

    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    ret = sortedSquares(arr, len, &retlen);
        
    for(int i = 0; i < retlen; i++)
        printf("%d ", ret[i]);

    return 0;
}