#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)


int minSubArrayLen(int target, int* nums, int numsSize) {

    if(numsSize == 1)
        return (nums[0] >= target) ? 1 : 0;
        
    int subarray = __INT_MAX__;
    int start = 0, end = -1;
    int sum = 0;
    int sub = 0;

    for(int i = 0; i < numsSize; i++){
        
        sum += nums[i];
        if(sum >= target) {
            if(subarray > sub + 1)
                subarray = sub + 1;
            end = start + sub;
            break;
        }
        else
            sub++;
    }

    if (subarray == 1)
        return 1;
    if (subarray == numsSize && sum == target)
        return numsSize;

    sum -= nums[start];
    start++;
    while(start < numsSize && end < numsSize)
    {    
        if(sum >= target) {
            sum -= nums[start];
            start += 1;
            subarray -= 1;
            if(subarray == 1)
                return 1;
        }
        else {
            sum -= nums[start];
            start += 1;
            end += 1;
            if(end < numsSize)
                sum += nums[end];
        }
    }

    return (subarray == __INT_MAX__) ? 0 : subarray;
}

int minSubArrayLen2(int target, int* nums, int numsSize) {
    int left = 0;
    int sum = 0;
    int minLength = __INT_MAX__;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        while (sum >= target) {
            int length = right - left + 1;

            if (length < minLength) {
                minLength = length;
            }

            sum -= nums[left];
            left++;
        }
    }

    if (minLength == __INT_MAX__) {
        return 0;
    }

    return minLength;
}

int main()
{
    int arr[] = {2, 14};
    int len = LEN(arr);
    int target  = 15;

    printf("\nresult = %d\n", minSubArrayLen(target, arr, len));

    return 0;
}