#include <limits.h>
#include <stdio.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        long num = nums[i];

        if (num == first || num == second || num == third)
            continue;

        if (num > first) {
            third = second;
            second = first;
            first = num;
        } 
        else if (num > second) {
            third = second;
            second = num;
        } 
        else if (num > third) {
            third = num;
        }
    }

    return third == LONG_MIN ? (int)first : (int)third;
}

int main()
{   
    int arr[] = {12, 32, 9292, 191};
    int len = LEN(arr);
    int max;

    max = thirdMax(arr, len);

    printf("%d\n", max);

    return 0;
}