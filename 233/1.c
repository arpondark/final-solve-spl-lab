#include <stdio.h>
#include <string.h>
#include <ctype.h>

void spellDigit(int digit, char* str) {
    switch (digit) {
        case 0: strcat(str, "zero "); break;
        case 1: strcat(str, "one "); break;
        case 2: strcat(str, "two "); break;
        case 3: strcat(str, "three "); break;
        case 4: strcat(str, "four "); break;
        case 5: strcat(str, "five "); break;
        case 6: strcat(str, "six "); break;
        case 7: strcat(str, "seven "); break;
        case 8: strcat(str, "eight "); break;
        case 9: strcat(str, "nine "); break;
        default: break; // Should never happen
    }
}

void toSpelledOut(int number, char* str) {
    // Clear the output string
    str[0] = '\0';

    // Handle negative numbers (optional, based on your note)
    if (number < 0) {
        strcat(str, "negative ");
        number = -number; // Make it positive for processing
    }

    // Process each digit
    int digits[20]; // Array to store digits
    int count = 0;

    // Extract digits
    while (number > 0) {
        digits[count++] = number % 10;
        number /= 10;
    }

    // Print digits in reverse order
    for (int i = count - 1; i >= 0; i--) {
        spellDigit(digits[i], str);
    }
}

void upperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int number;
    char str[100]; // Buffer to hold the spelled-out string
    char choice;

    // Ask for a number
    printf("Enter a number (do not start or end with 0): ");
    scanf("%d", &number);

    // Ask for case choice
    printf("Do you want the output in uppercase (U) or lowercase (L)? ");
    scanf(" %c", &choice);

    toSpelledOut(number, str);

    // Print the spelled-out number in the chosen case
    if (choice == 'U' || choice == 'u') {
        upperCase(str);
    }

    printf("%s\n", str);

    return 0;
}
