#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 100

// Define the Train structure
struct Train {
    char name[50];
    int totalTickets;
    float ratings;
};

// Function prototypes
void addTrain(struct Train listOfTrains[], int *numOfTrains);
void displayAllTrains(struct Train listOfTrains[], int numOfTrains);
int mostPopularTrain(struct Train listOfTrains[], int numOfTrains);

int main() {
    struct Train listOfTrains[MAX_TRAINS];
    int numOfTrains = 0;
    int choice;

    while (1) {
        printf("\n1. Add a train\n");
        printf("2. Most Popular Train\n");
        printf("3. List of the trains\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addTrain(listOfTrains, &numOfTrains);
                break;
            case 2: {
                int index = mostPopularTrain(listOfTrains, numOfTrains);
                if (index != -1) {
                    printf("Name of the Most Popular Train: %s\n", listOfTrains[index].name);
                } else {
                    printf("No trains available.\n");
                }
                break;
            }
            case 3:
                displayAllTrains(listOfTrains, numOfTrains);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a train
void addTrain(struct Train listOfTrains[], int *numOfTrains) {
    if (*numOfTrains >= MAX_TRAINS) {
        printf("Cannot add more trains. Maximum limit reached.\n");
        return;
    }

    printf("Enter train name: ");
    scanf("%[^\n]%*c",listOfTrains[*numOfTrains].name);
     // Remove newline character

    printf("Enter total tickets: ");
    scanf("%d", &listOfTrains[*numOfTrains].totalTickets);
    
    printf("Enter ratings: ");
    scanf("%f", &listOfTrains[*numOfTrains].ratings);
    getchar(); // To consume the newline character

    (*numOfTrains)++;
}

// Function to display all trains
void displayAllTrains(struct Train listOfTrains[], int numOfTrains) {
    if (numOfTrains == 0) {
        printf("No trains available.\n");
        return;
    }

    printf("\nList of Trains:\n");
    for (int i = 0; i < numOfTrains; i++) {
        printf("Train Name: %s\n", listOfTrains[i].name);
        printf("Total Tickets: %d\n", listOfTrains[i].totalTickets);
        printf("Ratings: %.1f\n", listOfTrains[i].ratings);
        printf("-------------------------\n");
    }
}

// Function to find the most popular train
int mostPopularTrain(struct Train listOfTrains[], int numOfTrains) {
    if (numOfTrains == 0) return -1; // No trains available

    int maxIndex = 0; // Start with the first train
    for (int i = 1; i < numOfTrains; i++) {
        if (listOfTrains[i].totalTickets > listOfTrains[maxIndex].totalTickets) {
            maxIndex = i; // Update index if current train has more tickets
        }
    }
    return maxIndex; // Return index of the most popular train
}
