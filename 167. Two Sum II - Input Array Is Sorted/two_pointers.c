#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    int index;
    int peek;

    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    index = 0;
    while(index < numbersSize)
    {
        peek = index + 1; 
        while(peek < numbersSize && numbers[peek] < target)
        {
            if((numbers[index] + numbers[peek]) == target)
            {
                result[0] = index + 1;
                result[1] = peek + 1;
                break;
            }
            if(numbers[peek] == numbers[index])
                index = peek;
            peek++;
        }
        index++;
    }
    return result;
}


int* twoSum2(int* numbers, int numbersSize, int target, int* returnSize) {
    
    int left = 0;
    int right = numbersSize - 1;

    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if(sum == target)
        {
                result[0] = left + 1;
                result[1] = right + 1;
                return result;
        }
        else if (sum > target)
            right--;
        else
            left++;
    }
    return result;
}

int main()
{
    int arr[] = {2,7,11,15};
    int len = LEN(arr);
    int target = 9;
    
    int *result;
    int returnlen;

    result = twoSum(arr, len, target, &returnlen);

    for(int i = 0; i < returnlen; i++)
        printf("%d ", result[i]);

    return 0;
}