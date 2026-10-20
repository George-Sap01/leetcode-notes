#include <stdio.h>
#include <stdbool.h>

#define LEN(arr) sizeof(arr)/sizeof(int)


bool checkIfExist(int* arr, int arrSize) {
    int i, j;

    // arr[i] % 2 = 0
    for(i = 0; i<arrSize; i++) {
        if(arr[i] % 2 == 0)
        {
            for(j=0; j<arrSize; j++)
            {
                if(j == i)
                    continue;

                if(arr[i] == (2 * arr[j]))
                    return true;
            }
        }

    }
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