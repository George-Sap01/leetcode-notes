#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)


int pivotIndex(int* nums, int numsSize) {
    
    int ret = -1;
 
    int total = 0;
    for(int i = 0; i < numsSize; i++)
        total += nums[i];
    
    int left_sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        printf("left_sum = %d,  total = %d\n", left_sum, total);
        if(left_sum == total - nums[i])
            return i;
        left_sum += nums[i];
        total -= nums[i];
    }


    return ret;   
}

int main()
{
    int arr[] = {1,7,3,6,5,6};
    int arr1[] = {-1, -1, -1, -1, -1};
    int len = LEN(arr);


    printf("%d\n", pivotIndex(arr, len));

    return 0;
}