#include <stdio.h>   // Standard input/output functions
#include <stdlib.h>  // For atoi() and malloc()
#include <string.h>  // For string manipulation functions
#include <stdbool.h> // To use boolean data type
#define MAX_LENGTH 100  // Define a constant for maximum input length

// Converts a substring of digits to an integer
// Takes the input string `s`, a starting index `start`, and the length of the substring
int substringToInt(const char *s, int start, int length) {
    char *buffer = (char *)malloc(length + 1);  // Allocate memory for the substring (plus null terminator)
    strncpy(buffer, s + start, length);         // Copy the substring from `s` starting at `start` of given `length`
    buffer[length] = '\0';                      // Null-terminate the string
    int value = atoi(buffer);                   // Convert the substring to an integer
    free(buffer);                               // Free the allocated memory
    return value;                               // Return the integer value
}

// Recursively checks if a valid split exists starting from `start` index
// `prevValue` holds the previous value to compare with
bool isValidSplit(const char *s, int start, int prevValue) {
    int len = strlen(s);  // Get the length of the string

    // Iterate through all possible substring lengths starting from `start`
    for (int i = 1; i <= len - start; i++) {
        int currentValue = substringToInt(s, start, i);  // Convert the current substring to an integer
        
        // Check if current value is greater or equal to previous (not descending)
        if (currentValue >= prevValue) {
            // Skip to next iteration if the current value is not smaller than previous
            continue;
        }
        
        // Check if the difference between previous and current values is exactly 1
        if (prevValue - currentValue != 1) {
            // If the difference is not 1, skip to the next iteration
            continue;
        }

        // If we've reached the end of the string and the conditions are met, return true
        if (start + i == len) {
            return true;
        }

        // Recursively check if the rest of the string can also be split correctly
        if (isValidSplit(s, start + i, currentValue)) {
            return true;
        }
    }
    // Return false if no valid split was found
    return false;
}

// Main function to check if the string can be split into descending consecutive substrings
bool canSplitIntoDescendingSubstrings(const char *s) {
    int len = strlen(s);  // Get the length of the string

    // Try splitting the string starting from every possible initial substring
    for (int i = 1; i < len; i++) {
        int firstValue = substringToInt(s, 0, i);  // Get the first substring's value
        
        // If a valid split is found from this point, return true
        if (isValidSplit(s, i, firstValue)) {
            return true;
        }
    }

    // Return false if no valid split was found for any possible initial partition
    return false;
}

int main() {
    char input[MAX_LENGTH];  // Buffer to hold the input string

    // Prompt the user to enter a string of digits
    printf("Enter a string of digits: ");
    
    // Read input from the user and check if reading was successful
    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("Error reading input");  // Print error if reading fails
        return 1;                       // Exit with error code
    }

    // Remove the newline character that fgets includes
    input[strcspn(input, "\n")] = '\0';

    // Check if the string can be split into valid descending consecutive substrings
    bool result = canSplitIntoDescendingSubstrings(input);

    // Print the result
    printf("Can split '%s': %s\n", input, result ? "true" : "false");

    return 0;  // Exit the program
}

