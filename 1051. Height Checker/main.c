#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)


int heightChecker(int* heights, int heightsSize) {
    
    int ret = 0;
    int expected[heightsSize];

    for(int i = 0; i < heightsSize; i++)
        expected[i] = heights[i];        

    // sort expected array with selection sort 
    for(int i = 0; i < heightsSize; i++)
    {
        int temp;
        int min = expected[i];
        int index_min = i;
        for(int j = i+1; j<heightsSize; j++)
        {
            if(expected[j] < min) {
                min = expected[j];
                index_min = j;
            }
        }
        
        temp = expected[i];
        expected[i] = min;
        expected[index_min] = temp;
    }
    

    // calculate ret
    for(int i = 0; i < heightsSize; i++)
        if(heights[i] != expected[i])
            ret++;


    return ret;
}


int main()
{

    int heights[] = {1, 4, 120, 38, 102};
    int len = LEN(heights);
    int ret;

    ret = heightChecker(heights, len);

    printf("ret = %d\n", ret);

    return 0;
}