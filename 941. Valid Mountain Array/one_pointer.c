#include <stdio.h>
#include <stdbool.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

bool validMountainArray(int* arr, int arrSize){
 
    if(arrSize < 3)
        return false;

    int i = 0;
    
    while((i+1 < arrSize) && (arr[i] < arr[i+1]))
        i++;

    if(i==0 || i==arrSize-1)
        return false;

    while((i+1 < arrSize) && (arr[i] > arr[i+1]))
        i++;

    return i == arrSize-1;
}


int main()
{
    int arr[] = {7, 5, 3, 1};
    int len = LEN(arr);
    bool check;

    check = validMountainArray(arr, len);

    printf("%d ", check);
    
    return 0;
}