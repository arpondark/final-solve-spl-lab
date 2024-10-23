#include <stdio.h>

// Function to count the number of words in the string
int countWords(char str[]) {
    int count = 0, inWord = 0;
    while (*str) {
        if (*str == ' ') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Function to return the length of the nth word in the string
int nNoWordLength(char* str, int n) {
    int currentWord = 0, length = 0;
    
    // Traverse the string
    while (*str) {
        // Skip spaces
        while (*str == ' ') str++;
        
        // Now we're at the start of a word
        currentWord++;
        length = 0;
        
        // If this is the nth word, calculate its length
        if (currentWord == n) {
            while (*str && *str != ' ') {
                length++;
                str++;
            }
            return length;
        }
        
        // Skip the current word to move to the next one
        while (*str && *str != ' ') str++;
    }
    
    return 0; // If nth word doesn't exist
}

// Function to check if the string is a Lucky String
int luckyString(char* str) {
    int totalWords = countWords(str);
    int totalOddLength = 0;
    
    // Loop through odd-numbered words
    for (int i = 1; i <= totalWords; i += 2) {
        totalOddLength += nNoWordLength(str, i);
    }
    
    // If the total length of odd-numbered words is divisible by 7
    if (totalOddLength % 7 == 0) {
        return 1; // Lucky String
    }
    
    return 0; // Not a Lucky String
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);  // Take input
    
    // Check if the string is Lucky and print the result
    if (luckyString(input)) {
        printf("Yes, it's a Lucky String.\n");
    } else {
        printf("No, it's not a Lucky String.\n");
    }
    
    return 0;
}
