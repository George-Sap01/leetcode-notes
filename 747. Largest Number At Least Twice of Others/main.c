#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)


int dominantIndex(int* nums, int numsSize) {
    
    int index;
    // x1 x2 x3 where x3 = max{x1, x2, x3}
    // if x3 >= x2 * 2 and x2 > x1 => x3 > x1 * 2
    // we need to find the max and the second max

    // using a version of selection sort     
    int temp;
    int max;
    int max_index;
    for(int i = 0; i < 2; i++)
    {
        max = nums[i];
        max_index = i;
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[j] > max) {
                max = nums[j];
                max_index = j;
            }
        }

        if(i == 0)
            index = max_index;

        temp = nums[i];
        nums[i] = max;
        nums[max_index] = temp;
    }

    if(nums[0] >= nums[1] * 2)
        return index;

    return -1;
}


// more compact and easier way
int dominantIndex2(int* nums, int numsSize) {
    
    int max = -1, second = -1, max_index = -1;
    int i;
    // x1 x2 x3 where x3 = max{x1, x2, x3}
    // if x3 >= x2 * 2 and x2 > x1 => x3 > x1 * 2
    // we need to find the max and the second max
    for(int i = 0; i < numsSize; i++){

        if(nums[i] > max) {
            second = max;
            max = nums[i];
            max_index = i;
        }
        else if(second < nums[i])
            second = nums[i];
    }

    if(max >= second * 2)
        return max_index;

    return -1;
}

int main()
{
    int arr[] = {1,3, 12, 4, 5};
    int len = LEN(arr);


    printf("%d\n", dominantIndex(arr, len));

    return 0;
}