#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100 // Define the maximum number of students

// Define the structure to store student information
struct Student {
    char name[100];
    int id;          // 5-digit ID
    float cgpa;     // CGPA
};

// Function to add a student to the list
void addStudent(struct Student listOfStudents[], int *numOfStudents) {
    if (*numOfStudents >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    

    printf("Name of the student: ");
    scanf(" %[^\n]%*c", listOfStudents[*numOfStudents].name); // Read string with spaces
    printf("ID: ");
    scanf("%d", &listOfStudents[*numOfStudents].id);
    printf("Cgpa: ");
    scanf("%f", &listOfStudents[*numOfStudents].cgpa);

    // Add the new student to the list
    
    (*numOfStudents)++;
    printf("Student added successfully.\n");
}

// Function to find the highest ranked student using recursion
void highestRankedStudent(struct Student listOfStudents[], int numOfStudents, int index, float *highestCGPA, char highestStudent[]) {
    // Base case: when the index reaches the number of students
    if (index == numOfStudents) {
        return;
    }

    // Check if the current student has a higher CGPA
    if (listOfStudents[index].cgpa > *highestCGPA) {
        *highestCGPA = listOfStudents[index].cgpa;
        strcpy(highestStudent, listOfStudents[index].name); // Update the highest ranked student's name
    }

    // Recursive call for the next student
    highestRankedStudent(listOfStudents, numOfStudents, index + 1, highestCGPA, highestStudent);
}

// Function to display all students
void displayAllStudents(struct Student listOfStudents[], int numOfStudents) {
    if (numOfStudents == 0) {
        printf("No students available.\n");
        return;
    }
    printf("List of Students:\n");
    for (int i = 0; i < numOfStudents; i++) {
        printf("Name: %s, ID: %05d, CGPA: %.2f\n", listOfStudents[i].name, listOfStudents[i].id, listOfStudents[i].cgpa);
    }
}

int main() {
    struct Student listOfStudents[MAX_STUDENTS];
    int numOfStudents = 0;
    int choice;

    while (1) {
        // Display menu
        printf("\n1. Add a student\n");
        printf("2. Highest Ranked Student\n");
        printf("3. List of the students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(listOfStudents, &numOfStudents);
                break;
            case 2: {
                if (numOfStudents == 0) {
                    printf("No students available to determine the highest ranked student.\n");
                } else {
                    float highestCGPA = 0.0;
                    char highestStudent[100] = "";
                    highestRankedStudent(listOfStudents, numOfStudents, 0, &highestCGPA, highestStudent);
                    printf("Name of the Highest Ranked Student: %s\n", highestStudent);
                }
                break;
            }
            case 3:
                displayAllStudents(listOfStudents, numOfStudents);
                break;
            case 4:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
