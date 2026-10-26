#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)

int thirdMax(int* nums, int numsSize) {
    
    int third_max = 0;
    int cnt = 1;
    int temp;

    if(numsSize == 1)
        return nums[0];

    // sorting the nums array with selection sort.
    for(int i = 0; i < numsSize; i++)
    {
        int max = nums[i];
        int max_index = i;
        for(int j = i + 1; j < numsSize; j++) {
            
            if(max < nums[j]) {
                max = nums[j];
                max_index = j;
            }
        }
        temp = nums[i];
        nums[i] = max;
        nums[max_index] = temp;
    }    


    int max = nums[0];
    for(int i = 0; i < numsSize; i++) {

        if(nums[i] < max){
            max = nums[i];
            cnt++;
        }

        if(cnt == 3)
            return max;
    }

    return nums[0];
}


int main()
{
    int arr[] = {1, 4, 120, 38, 102};
    int len = LEN(arr);


    for(int i = 0; i <len; i++)
        printf("%d ", arr[i]);

    printf("%d\n", thirdMax(arr, len));

    return 0;
}