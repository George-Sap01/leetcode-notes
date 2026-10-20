#include <stdio.h>
#include <stdbool.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

bool validMountainArray(int* arr, int arrSize){
 
    if(arrSize < 3)
        return false;

    int right = arrSize-1 , left = 0;
    int check_l = 0, check_r = 0;
 
    while((left < arrSize-1) && (arr[left] < arr[left+1])) {
        left++;
        check_l = 1;
    }
    
    while((right-1 > 0) && (arr[right-1] > arr[right])) {
        check_r = 1;
        right--;
    }
    
    return (right == left) && (check_l + check_r == 2);
}


int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int len = LEN(arr);
    bool check;

    check = validMountainArray(arr, len);

    printf("%d ", check);
    
    return 0;
}