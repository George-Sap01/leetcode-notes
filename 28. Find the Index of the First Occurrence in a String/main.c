#include <stdio.h>

int len(char *str) {
    int cnt = 0;
    while(str[cnt++] != '\0');
    return cnt - 1;
}

int strStr(char* haystack, char* needle) {
    
    int len_heystack = len(haystack);
    int len_needle = len(needle);
    
    if(len_heystack < len_needle || len_needle == 0)
            return -1;
    
    for(int i = 0; i < len_heystack; i++)
    {
        if(len_heystack - i < len_needle)
            return -1;

        if(haystack[i] == needle[0])
        {
            int k = 1;
            while(haystack[i+k] == needle[k] && k < len_needle) 
                k++;
            if(k == len_needle)
                return i;
        }
    }
    
    return -1;
}


int main()
{   
    char *heystack = "Leetcode";
    char *needle = "code";
    
    printf("index = %d", strStr(heystack, needle));
    return 0;
}