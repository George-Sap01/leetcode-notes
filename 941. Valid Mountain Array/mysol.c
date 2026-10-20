#include <stdio.h>
#include <stdbool.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

bool validMountainArray(int* arr, int arrSize){
 
    int i, flag = 0;
    int right = 0 , left = 0;
 
    for(i= 0; i < arrSize-1; i++) {
        if(arr[i] == arr[i+1])
            return false;

        printf("arr[%d] = %d, flag=%d, left=%d, right=%d\n", i, arr[i], flag, left, right);
        if(flag == 0) {
            if(arr[i] < arr[i+1]) {
                left = 1;
                continue;
            }
            else {
                right = 1;
                flag = 1;
            }
        }
        else {
            if(arr[i+1] < arr[i])
                continue;
            else
                return false;                
        }
    }

    return true ? (right + left == 2) : false;
}


int main()
{
    int arr[] = {1, 3, 2};
    int len = LEN(arr);
    bool check;

    check = validMountainArray(arr, len);

    printf("%d ", check);
    
    return 0;
}