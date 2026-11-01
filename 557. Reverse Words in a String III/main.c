#include <string.h>
#include <stdio.h>


char* reverseWords(char* s) {
    int left, right;
    int start = 0;
    int end = start;
    char temp;
    while(start <= strlen(s)-1)
    {
        while(s[end] != ' ' && s[end] != '\0') 
            end++;
        
        left = start;
        right = end - 1;
        while(left <= right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--;
            left++;
        }
        start = end + 1;
        end = start;
    }

    return s;
}

int main()
{
    char str[] = "Hello World";

    printf("%s", reverseWords(str));



    return 0;
}