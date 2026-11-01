#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    
    if(sSize == 0 || sSize == 1)
        return;  
    
        int left = 0;
    int right = sSize - 1;

    while(left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}



int main()
{
    char str[] = "Hello";

    reverseString(str, strlen(str));
    printf("%s", str);


    return 0;
}