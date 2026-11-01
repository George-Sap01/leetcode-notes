#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    
    int max  = 0;
    int cnt  = 0;
    int prev = 0;  
    
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==1 && prev==0) {    
            cnt = 1;
            prev = 1;
        }
        else if(nums[i]==1 && prev==1)
            cnt++;

        if (nums[i] == 0) {
            if(max < cnt)
                max = cnt;
            cnt = 0;
            prev = 0;
        }
    }

    if(max < cnt)
        max = cnt;
        
    return max;
}

int findMaxConsecutiveOnes2(int* nums, int numsSize) {
    
    int max  = 0;
    int cnt = 0;
    
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==1)
        {    
            cnt++;
            if(cnt > max)
                max = cnt;
        }
        else
            cnt = 0;
    }
    return max;
}


int main()
{
    int arr[] = {1, 0, 1, 1, 1, 0, 0, 1};
    int len = LEN(arr);

    printf("max = %d\n", findMaxConsecutiveOnes2(arr, len));


    return 0;
}