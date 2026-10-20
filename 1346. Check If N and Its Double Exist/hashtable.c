#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN(arr) sizeof(arr)/sizeof(int)

/*
    arr[i] == 2 * arr[j]

    this is for i 
    arr[i] % 2 == 0 && hashtable[arr[i]/2 + 1000]

    this is for j 
    hashtable[arr[i] * 2 + 1000]

*/

bool checkIfExist(int* arr, int arrSize) {

    int* hashtable = (int*)calloc(2001, sizeof(int));  // -1000 ... 1000 possible values of array.    
    for(int i=0; i<arrSize; i++)
    {
        int hash_index = arr[i] + 1000;
        if( (arr[i] % 2 == 0 && hashtable[arr[i]/2 + 1000]) || hashtable[arr[i] * 2 + 1000])
        {
            free(hashtable);
            return true;
        }
        hashtable[hash_index] = 1;
    }

    free(hashtable);
    return false;
}



int main()
{
    int arr[] = {10,2,5,3};
    int len = LEN(arr);
    bool check;

    check = checkIfExist(arr, len);
    printf("check is %d", check);

    return 0;
}