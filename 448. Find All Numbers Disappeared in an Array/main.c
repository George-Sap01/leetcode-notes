#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    
    int *ret = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    int arr[numsSize];
    memset(arr, 0, sizeof(int) * numsSize);

    for(int i = 0; i < numsSize; i++)
        arr[nums[i] - 1] = 1;
    
    for(int i = 0; i < numsSize; i++) {   
        if(arr[i] == 0) {
            ret[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }
    
    return ret;
}


int* findDisappearedNumbers2(int* nums, int numsSize, int* returnSize) {
    
    int *ret = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++)
        ret[nums[i] - 1] = nums[i];
    
    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        // printf("left:%d = %d,  right:%d = %d\n", left, ret[left], right, ret[right]);
        if(ret[left] == 0) {
            ret[left] = left + 1;
            left++;
            (*returnSize)++; 
        }
        else {

            if(ret[right] == 0) {
                ret[left] = right + 1;
                (*returnSize)++; 
                left++;
                right--;
            }
            else {
                right--;
                continue;
            }
        }

    }
    
    return ret;
}

int main()
{   
    int arr[] = {1, 1};
    int len = LEN(arr);

    int *ret;
    int retlen;

    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    ret = findDisappearedNumbers2(arr, len, &retlen);
        
    for(int i = 0; i < retlen; i++)
        printf("%d ", ret[i]);

    return 0;
}