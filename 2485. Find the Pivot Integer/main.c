#include <stdio.h>

/*
 n = 4: 
        1 2 3 4 
 n = 8:
        1 2 3 4 5 6 7 8

    sum from 1 to μ = μ(μ+1)/2
n = 2:
     1  2 

n = 5:
    1 2 3 4 5
    
*/

int pivotInteger(int n) {
    if(n == 1)
        return n;
    else if(n == 2)
        return -1;
    else
    {
        for(int i=2; i<n; i++)
            if( i*i == (n*(n+1)/2) )
                return i;
    }
    return -1;
}


int main()
{
    int n = 8;
    
    int res = pivotInteger(n);

    printf("%d\n", res);


    return 0;
}