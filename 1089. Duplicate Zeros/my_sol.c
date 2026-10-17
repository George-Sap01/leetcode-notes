#include <stdio.h>


void duplicateZeros(int* arr, int arrSize) {
    
    for(int i=0; i<arrSize; i++) {
           
        if(arr[i] == 0) {
            for(int j = arrSize-1; j>i; j--) {
                arr[j] = arr[j-1];
            }
            i++;
        }
    
    }
}


int main()
{
    int arr1[] = {1,0,2,3,0,4,5,0};
    int len_arr1 = sizeof(arr1)/sizeof(int);
    // [1,0,0,2,3,0,0,4]
    int arr2[] = {1,2,3};
    int len_arr2 = sizeof(arr2)/sizeof(int);
    // {1,2,3} 

    duplicateZeros(arr1, len_arr1);

    for(int i=0; i<len_arr1; i++) 
        printf("%d\t",arr1[i]);

    return 0;
}