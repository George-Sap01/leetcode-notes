#include <stdio.h>
#include <stdlib.h>

int len(char *str) {
    int cnt = 0;
    while(str[cnt++] != '\0');
    return cnt - 1;
}

// More elegant, more compact and faster than my solution.
char* addBinary(char* a, char* b) {
    int LenA = len(a);
    int LenB = len(b);
    int maxLen = (LenA >= LenB ? LenA : LenB) + 1;

    char* result = malloc((maxLen + 1) * sizeof(char));

    int i = LenA - 1;
    int j = LenB - 1;
    int carry = 0, k = 0;

    while(i >= 0 || j >= 0 || carry){
        int sum = carry;

        if(i >= 0){
            sum += a[i] - '0';
            i--;
        }

        if(j >= 0){
            sum += b[j] - '0';
            j--;
        }

        result[k] = (sum % 2) + '0';
        k++;
        carry = sum / 2;
    }
    result[k] = '\0';

    // reverse the elements to put them in correct order. 
    for(int left = 0, right = k - 1; left < right; left++, right--){
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    return result;
}

int main()
{
    char *str1 = "10000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100";
    char *str2 = "100101010101101010100101010010011011110101010110000000000000101010011111100101001010101001111000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100";    // result = 110110
    // result = 110110
    char *result;
    int result_index = 0;

    result = addBinary(str1, str2);
    
    for(int i = 0; i < len(result); i++) 
        printf("%c", result[i]);


    return 0;
}