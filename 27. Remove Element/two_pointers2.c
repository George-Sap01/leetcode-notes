#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int removeElement(int* nums, int numsSize, int val) {
    
    int idx = 0;
    for(int i=0; i<numsSize; i++) {
        // printf("arr[idx = %d] = %d , arr[i = %d] = %d\n", idx, nums[idx], i, nums[i]);
        if(nums[i] != val)
        {
            nums[idx] = nums[i];
            idx++;
        }
    }
    
    return idx;
}

int main()
{
    int ret;
    int val = 2;
    int arr[] = {0,1,2,2,3,0,4,2};
    int len = LEN(arr);


    ret = removeElement(arr, len, val);


    for(int i=0; i<ret; i++)
        printf("%d ", arr[i]);

    return 0;
}

