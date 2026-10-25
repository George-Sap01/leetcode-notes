#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)

void duplicateZeros(int* arr, int arrSize) {
    int countZero = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) 
            countZero++;
    }

    int len = arrSize + countZero;
    printf("countzero = %d, size+countzero = %d\n", countZero, len);
    // We just need O(1) space if we scan from back
    // i point to the original array, j point to the new location
    for (int i = arrSize - 1, j = len - 1; i < j; i--, j--) {
        printf("arr[i = %d] = %d,  arr[j = %d] = %d\n", i, arr[i], j, arr[j]);
        if (arr[i] != 0) 
        {
            if (j < arrSize) 
                arr[j] = arr[i];
        } 
        else 
        {
            if (j < arrSize) 
                arr[j] = arr[i];

            j--;

            if (j < arrSize) 
                arr[j] = arr[i]; //copy twice when hit '0'
        }
    }
}
/* 
    [1,0,2,3,0,4,5,0]
    countzero = 3
    len = 8 + 3
    size = 8

    i=7, j=10:
        arr[7] = 0:
            10 < 8
            j = 9
            9 < 8 
    i=6, j=8:
        arr[6] = 5:
            8 < 8
    i=5, j=7:
        arr[5] = 4:
            7 < 8:
                arr[7] = arr[5] = 4
    i=4, j=6:
        arr[4] = 0:
            arr[6] = arr[4] = 0
            j = 5
            arr[5] = arr[4] = 0 
    i=3, j=4:
        arr[3] = 3;
            arr[4] = arr[3] = 3
    i=2, j=3:
        arr[2] = 2:
            arr[3] = arr[2] = 0
    i=1, j=2:
        arr[1] = 0
        2 < 8:
            arr[2] = arr[1] = 0
            j=1
            arr[1] = arr[1] = 0
    
*/

/*
    -------------------------------------------------------------
    | 1  | 0  | 2  | 3  | 0  | 5  | 6  | _  | _  | _  | _  | _  |
    |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |
    |    |    |    |    |    |    |i=6 |    |j=8 |    |    |    |                           
    |    |    |    |    |    |i=5 |    |j=7 |    |    |    |    |
    |    |    |    |    |i=4 |    |j=6 |    |    |    |    |    |                           
    |    |    |    |    |i=4 |j=5 |    |    |    |    |    |    |
    |    |    |    |i=3 |j=4 |    |    |    |    |    |    |    |                           
    |    |    |i=2 |j=3 |    |    |    |    |    |    |    |    |
    |    |i=1 |j=2 |    |    |    |    |    |    |    |    |    |                           
    |    |i=1 |    |    |    |    |    |    |    |    |    |    |
         |j=1 |
    -------------------------------------------------------------

    -------------------------------------------------------------
    | 1  | 0  | 2  | 3  | 5  | 0  | 6  | _  | _  | _  | _  | _  |
    |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |--- |
    |    |    |    |    |    |    |i=6 |    |j=8 |    |    |    |                           
    |    |    |    |    |    |i=5 |    |j=7 |    |    |    |    |
    |    |    |    |    |    |i=5 |j=6 |    |    |    |    |    |                           
    |    |    |    |    |i=4 |j=5 |    |    |    |    |    |    |
    |    |    |    |i=3 |j=4 |    |    |    |    |    |    |    |                           
    |    |    |i=2 |j=3 |    |    |    |    |    |    |    |    |
    |    |i=1 |j=2 |    |    |    |    |    |    |    |    |    |                           
    |    |i=1 |    |    |    |    |    |    |    |    |    |    |
         |j=1 |
    -------------------------------------------------------------
*/

int main()
{

    int arr1[] = {1,0,2,3,0,4,5,0};
    int len_arr1 = LEN(arr1);
    // [1,0,0,2,3,0,0,4]
    int arr2[] = {1,2,3};
    int len_arr2 = LEN(arr2);
    // {1,2,3} 
    int arr3[] = {1,0,0,4,5};
    int len_arr3 = LEN(arr3);

    
    for(int i=0; i<len_arr1; i++) 
        printf("%d ",arr1[i]);

    printf("\n");
    duplicateZeros(arr1, len_arr1);

    for(int i=0; i<len_arr1; i++) 
        printf("%d\t",arr1[i]);


    return 0;
}
