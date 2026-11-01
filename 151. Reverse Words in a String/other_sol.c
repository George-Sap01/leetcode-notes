#include <string.h>
#include <stdio.h>

// Helper function to reverse a segment of a string in place
void reverse(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    if (s == NULL) return s;

    int len = strlen(s);
    
    // Step 1: Reverse the entire string
    reverse(s, s + len - 1);

    // Step 2: Reverse each individual word and clean up extra spaces
    int write_idx = 0;
    int read_idx = 0;

    while (read_idx < len) {
        // Skip leading/multiple spaces
        while (read_idx < len && s[read_idx] == ' ') {
            read_idx++;
        }

        // Break if we reached the end of the string
        if (read_idx >= len) break;

        // Add a single space separator if this isn't the very first word
        if (write_idx > 0) {
            s[write_idx++] = ' ';
        }

        // Mark the start of the current word
        int word_start = write_idx;

        // Copy the word to its new compacted position
        while (read_idx < len && s[read_idx] != ' ') {
            s[write_idx++] = s[read_idx++];
        }

        // Reverse the individual word back to its correct reading order
        reverse(s + word_start, s + write_idx - 1);
    }

    // Step 3: Add the null terminator to truncate any trailing garbage
    s[write_idx] = '\0';

    return s;
}



int main()
{
    
    char str[] = "1234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890101234567890107";
    printf("result = '%s'", reverseWords(str), str);

    return 0;
}