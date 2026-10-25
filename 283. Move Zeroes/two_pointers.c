#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)


void moveZeroes(int* nums, int numsSize) {
    int index = 0;
    int peek = index + 1; 

    while(peek < numsSize && index < numsSize)
    {
        if(nums[index] == 0)
        {
            if(nums[peek] == 0) {
                peek++;
                continue;
            }
            else {
                nums[index] = nums[peek];
                nums[peek] = 0;
                peek++;                
            }
        }
        index++;

        if(index >= peek)
            peek = index + 1;
    }
}


int main()
{
    int nums[] = {0,1,0,3,12};
    int len = LEN(nums);


    for(int i = 0; i<len; i++)
        printf("%d ", nums[i]);

    moveZeroes(nums, len);
    printf("\n");
    for(int i = 0; i<len; i++)
        printf("%d ", nums[i]);



    return 0;
}