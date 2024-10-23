#include <stdio.h>
#include <ctype.h>

// Function to count the number of words
int countWords(char *str) {
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

// Function to get the index of the middle word
void getMiddleWord(char str[], int *start, int *end) {
    int totalWords = countWords(str);
    int middle = (totalWords / 2) + 1;
    int currentWord = 0, i = 0;
    
    while (str[i] && currentWord < middle) {
        while (str[i] == ' ') i++; // Skip spaces
        currentWord++;
        if (currentWord == middle) {
            *start = i;  // Start of the middle word
            while (str[i] && str[i] != ' ') i++;
            *end = i;    // End of the middle word
            break;
        }
        while (str[i] && str[i] != ' ') i++; // Skip word
    }
}

// Function to check if the middle word is a Dragon word
int isDragon(char str[]) {
    int start, end;
    getMiddleWord(str, &start, &end);
    if (str[start] == '?' && str[end - 1] == '#') {
        for (int i = start + 1; i < end - 1; i++) {
            if (!isalpha(str[i])) {
                return 0; // Invalid character
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    gets(input);

    if (isDragon(input)) {
        printf("Yes, it's a Dragon String.\n");
    } else {
        printf("No, it's not a Dragon String.\n");
    }
    
    return 0;
}
