#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *str) {
    int cnt = 0;
    while(str[cnt++] != '\0');
    return cnt - 1;
}

char* longestCommonPrefix(char** strs, int strsSize) {

    char *pilot = strs[0];
    int k = 0;

    while(k < len(pilot))
    {
        int i = 1;
        while(i < strsSize) {
            if(k == 0 && len(strs[i]) == 0) {
                pilot[0] = '\0';
                return pilot;                
            }

            if(strs[i][k] == '\0' || pilot[k] != strs[i][k])
                break;
            else
                i++;
        }

        if(i != strsSize) {
            pilot[k] = '\0';
            return pilot;
        }
        else
            k++;
    }
    return pilot;
}

int main()
{   
    char s[][100]= {"flower","flow","flight"};
    char **strs;
    int cnt = 3;
    strs = (char**)malloc(sizeof(char*) * cnt);
    
    
    for(int i = 0; i < cnt; i++)
    {    
        strs[i] = (char*)malloc(sizeof(char) * 100);
        strcpy(strs[i], s[i]);
    }

    char *result = longestCommonPrefix(strs, cnt);


    // for(int i = 0; i<cnt; i++)
    //     printf("%s %s\n", s[i], strs[i]);
    
    
    printf("\n'%s'", result);

    return 0;
}