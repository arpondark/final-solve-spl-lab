#include <stdio.h>

// Function to get the last character of a string
char getLastChar(char str[]) {
    int i = 0;
    // Loop through the string to find the last character
    while (str[i] != '\0') {
        i++;
    }
    // Return the last character
    return str[i - 1];
}

// Function to check if the entity name is valid
int isValidEntity(char *entityName) {
    // Check the first character
    if (entityName[0] < 'A' || entityName[0] > 'Z') {
        return 0; // First character must be uppercase
    }

    // Check the last character
    char lastChar = getLastChar(entityName);
    if (lastChar < 'a' || lastChar > 'z') {
        return 0; // Last character must be lowercase
    }

    // Check for valid characters and special characters
    for (int i = 0; entityName[i] != '\0'; i++) {
        char c = entityName[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
            return 0; // Invalid character found
        }
    }

    return 1; // Entity name is valid
}

// Function to check if the entity is a cyber threat
int isCyberThreat(char *entityName, int threatLevel) {
    // Check validity of the entity name and threat level
    if (isValidEntity(entityName) && threatLevel > 50) {
        return 1; // It is a cyber threat
    }
    return 0; // It is not a cyber threat
}

int main() {
    char entityName[100]; // Assuming maximum entity name length is 99 characters
    int threatLevel;

    // Input entity name and threat level
    printf("Enter entity name: ");
    scanf("%s", entityName);
    printf("Enter threat level: ");
    scanf("%d", &threatLevel);

    // Check if the entity is a cyber threat and print the result
    if (isCyberThreat(entityName, threatLevel)) {
        printf("Cyber Threat Detected\n");
    } else {
        printf("Safe\n");
    }

    return 0;
}
