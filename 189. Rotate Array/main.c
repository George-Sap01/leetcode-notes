#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

void rotate(int* nums, int numsSize, int k) {

    if(k > numsSize)
        k = k % numsSize;
    int left;
    int right;
    int temp;
    // Using the reversal algorithm.

    // first subarray
    left = 0;
    right = numsSize - 1 - k;
    while(left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

    // the second subarray
    left = numsSize - k;
    right = numsSize - 1;
    while(left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

    // the whole array
    left = 0;
    right = numsSize - 1;
    while(left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int len = LEN(arr);

    // 3,99,-1,-100
    rotate(arr, len, 2);

    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    return 0;
}