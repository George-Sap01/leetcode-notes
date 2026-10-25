#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

// nums is a non-descending array.
int removeDuplicates(int* nums, int numsSize) {

    int index = 0;
    int peek = index + 1;

    while(peek < numsSize)
    {
        printf("nums[index = %d] = %d,  nums[peek = %d]=%d\n", index, nums[index], peek, nums[peek]);
        if(nums[peek] <= nums[index]) {
            peek++;
            continue;
        }
        index++;
        nums[index] = nums[peek];
    }

    return index+1;
}


int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    int len = LEN(arr);
    int k = 0;

    k = removeDuplicates(arr, len);

    for(int i=0; i<k; i++)
        printf("%d ", arr[i]);
    
    return 0;
}