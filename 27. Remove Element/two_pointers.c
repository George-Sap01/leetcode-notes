#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int removeElement(int* nums, int numsSize, int val) {
    int cnt = 0;
    int left = 0, right = numsSize -1;
    
    for(int k=0; k<numsSize; k++)
        if(nums[k] != val)
            cnt++;

    while(left <= right)
    {   
        // printf("nums[%d]= %d,  nums[%d]=%d\n", left, nums[left], right, nums[right]);
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

    return cnt;
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

