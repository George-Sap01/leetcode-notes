#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int removeElement(int* nums, int numsSize, int val) {
    
    int left = 0, right = numsSize -1;

    while(left <= right)
    {   
        printf("nums[%d]= %d,  nums[%d]=%d\n", left, nums[left], right, nums[right]);
        if(nums[left] == val) {
            if(nums[right] == val) {
                right--;
                continue;
            }
            nums[left] = nums[right];
            right--;
        }

        left++;
    }

    return left;
}

int main()
{
    int ret;
    int val = 2;
    int arr[] = {0, 1, 3, 0, 4, 2};
    int len = LEN(arr);

    for(int i=0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    ret = removeElement(arr, len, val);


    for(int i=0; i<ret; i++)
        printf("%d ", arr[i]);

    return 0;
}

