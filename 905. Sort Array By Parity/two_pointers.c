#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {

// mysol
#if 0
    int *ret = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    if(numsSize == 1) {
        ret[0] = nums[0];
        return ret; 
    }
   
    int even = 0;
    for(int i = 0; i < numsSize; i++)
        if(nums[i] % 2 == 0)
            even++;

    int index = 0;
    int peek = index + 1;
    while(index < even)
    {
        if(nums[index] % 2 != 0) {
            
            if(nums[peek] % 2 != 0) {
                peek++;
                continue;
            }
            else {
                ret[index] = nums[peek]; 
                nums[peek] = nums[index];
                peek++;
            }
        }
        else 
            ret[index] = nums[index];

        index++;
        if(peek >= index)
            peek = index + 1;
    }

    for(int i = index; i<numsSize; i++)
        ret[i] = nums[i];
    
    return ret;
#else 

    // EASIER SOLUTION AND FASTER

    int *result = (int*)malloc(numsSize*sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] % 2 == 0){
            result[left] = nums[i];
            left++;
        }
        else{
            result[right] = nums[i];
            right--;
        }
    }

    *returnSize = numsSize;
    return result; 

#endif

}



int main()
{
    int nums[] = {1, 0, 2};
    int len = LEN(nums);
    int *ret;
    int retsize;

    for(int i = 0; i<len; i++)
        printf("%d ", nums[i]);
        
    printf("\n");
    ret = sortArrayByParity(nums, len, &retsize);

    for(int i = 0; i<len; i++)
        printf("%d ", ret[i]);



    return 0;
}