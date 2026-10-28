#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // case 1: 9 1 2 
    // 9 1 2 + 1 = 9 1 3

    // case 2: 1 1 2 
    // 1 1 2 + 1 = 1 1 3

    // case 3: 1 3 9 
    // 1 3 9 + 1 = 1 4 0

    // case 4: 9 9 9  
    // 9 9 9 + 1 = 1 0 0 0

    int *ret  = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int add = 0;
    int last_digit = digits[digitsSize - 1] == 9;
    int i;
    
    if(last_digit) {

        for(i = digitsSize - 1; i > -1; i--) {
            if(digits[i] == 9 && add == 1 || i == digitsSize - 1) { 
                ret[i + 1]  = 0;
                add = 1;
            }
            else {
                ret[i + 1] = digits[i] + add;
                add = 0;
            }
       }
    }
    else{
        
        for(i = digitsSize - 1; i > -1; i--) {
           if(i == digitsSize - 1)
                ret[i] = digits[i] + 1;
            else
                ret[i] = digits[i];
        }

    }

    
    if(last_digit){
        printf("digits[i:%d] = %d, add = %d\n", i, digits[i], add);
        if(add == 1 && digits[0] == 9)
            ret[0] = 1;
        else
           ret = ret + 1; 
    }


    *returnSize = digitsSize + 1 * (last_digit && add == 1 && digits[0] == 9);
    return ret;
}


int main()
{
    int arr[] = {8, 9, 9, 9};
    int len = LEN(arr);
    int *ret;
    int retlen;

    for(int i = 0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    ret = plusOne(arr, len, &retlen);

    for(int i = 0; i<retlen; i++)
        printf("%d ", ret[i]);

    return 0;
}