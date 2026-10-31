#include <stdio.h>
#include <stdlib.h>

int len(char *str) {
    int cnt = 0;
    while(str[cnt++] != '\0');
    return cnt - 1;
}

/*
    a =   1 0 1 0 1  , len_a = 5
    b =          1 1 , len_b = 2
    max = 5 + 1 

      1 1 1 0
  +   1 0 1 1
    ----------
    1 1 0 0 1

        1 1
    +   0 1
    --------
       1 0 0
*/

char* addBinary(char* a, char* b) {
    
    int len_a = len(a);
    int len_b = len(b);
    int max_len = (len_a > len_b) ? len_a : len_b;

    char *str = (char*)malloc(sizeof(char) * (max_len + 1 + 1)); // 1 for the character = '\0', 1 in cases like 11 + 10 = 101

    int str_index = 0;
    int add = 0;

    str[max_len + 1] = '\0';
    str[0] = ' ';

    if(max_len == len_a)
    {
        while(str_index < len_b) {
            // 1: we add the numbers we have
            // 2: we add any residual from the previous addition
            // 3: we see if we have a residual 
            // how to check if we have a residual
            // if the addition of the numbers is 2 then add = 1
            // if the addition of the result of the addition of the numbers and the residual is 2 then add = 1
            if (a[len_a - 1 -  str_index] == '1' && b[len_b - 1 - str_index] == '1') {
                str[max_len - str_index] = '0' + add;
                add =  1;
            }
            else if (a[len_a - 1 -  str_index] == '0' && b[len_b - 1 - str_index] == '0') {
                str[max_len - str_index] = '0' + add;
                add =  0;
            }
            else if (add == 1 ) { // (a[len_a - 1 -  str_index] == '1' && b[len_b - 1 - str_index] == '0') || (a[len_a - 1 -  str_index] == '0' && b[len_b - 1 - str_index] == '1') 
                str[max_len - str_index] = '0';
                add =  1;
            }
            else {
                str[max_len - str_index] = '1';
                add =  0;
            }
            
            str_index++;
        }

        while(str_index < len_a) {   

            if (a[len_a - 1 -  str_index] == '1' && add == 1) {
                str[max_len - str_index] = '0';
                add =  1;
            }
            else if (a[len_a - 1 -  str_index] == '1' && add == 0) {
                str[max_len - str_index] = '1';
                add =  0;
            }
            else { // (a[len_a - 1 -  str_index] == '0') 
                str[max_len - str_index] = '0' + add;
                add =  0;
            }
            str_index++;
        }
    }
    else
    {
        while(str_index < len_a) {

            if (a[len_a - 1 -  str_index] == '1' && b[len_b - 1 - str_index] == '1') {
                str[max_len - str_index] = '0' + add;
                add =  1;
            }
            else if (a[len_a - 1 -  str_index] == '0' && b[len_b - 1 - str_index] == '0') {
                str[max_len - str_index] = '0' + add;
                add =  0;
            }
            else if (add == 1 ) { // (a[len_a - 1 -  str_index] == '1' && b[len_b - 1 - str_index] == '0') || (a[len_a - 1 -  str_index] == '0' && b[len_b - 1 - str_index] == '1') 
                str[max_len - str_index] = '0';
                add =  1;
            }
            else {
                str[max_len - str_index] = '1';
                add =  0;
            }
            
            str_index++;        
        }

        while(str_index < len_b) {

            if (b[len_b - 1 -  str_index] == '1' && add == 1) {
                str[max_len - str_index] = '0';
                add =  1;
            }
            else if (b[len_b - 1 -  str_index] == '1' && add == 0) {
                str[max_len - str_index] = '1';
                add =  0;
            }
            else {  //  b[len_b - 1 -  str_index] == '0' && add == 1
                str[max_len - str_index] = '0' + add;
                add =  0;
            }
            str_index++;
        }
    }
    
    if(add == 1)
        str[max_len - str_index] = '1';

    if (str[0] == ' ')
        str = str + 1;  

    return str;
}

int main()
{
    char *str1 = "10000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100";
    char *str2 = "100101010101101010100101010010011011110101010110000000000000101010011111100101001010101001111000000000000010101001010101101010010101000100100000000000001010100101010110101001010100010010000000000000101010010101011010100101010001001000000000000010101001010101101010010101000100";    // result = 110110
    char *result;
    int result_index = 0;

    result = addBinary(str1, str2);
    
    for(int i = 0; i < len(result); i++) 
        printf("%c", result[i]);


    return 0;
}