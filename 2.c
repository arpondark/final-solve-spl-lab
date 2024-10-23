#include <stdio.h>

struct Player {
    char username[50];
    int vitality, magic, defense, attack;
};

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to calculate sum of digits
int digitSum(int num) {
    if (num == 0) return 0;
    return (num % 10) + digitSum(num / 10);
}

// Function to calculate summation from 1 to num
int summation(int n) {
    return (n * (n + 1)) / 2;
}

// Function to check if a number is Spectacular
int isSpectacular(int num) {
    if (!isPrime(num)) return 0;
    int s = digitSum(num);
    return (summation(s) % (num % 10)) == 0;
}

int main() {
    struct Player p;
    int total;
    
    printf("Enter player username: ");
    scanf("%s", p.username);
    printf("Enter vitality: ");
    scanf("%d", &p.vitality);
    printf("Enter magic: ");
    scanf("%d", &p.magic);
    printf("Enter defense: ");
    scanf("%d", &p.defense);
    printf("Enter attack: ");
    scanf("%d", &p.attack);

    total = p.vitality + p.magic + p.defense + p.attack;
    
    if (isSpectacular(total)) {
        printf("%d is a spectacular number\n", total);
        printf("Luck value for player %s is: %d0\n", p.username, total);
    } else {
        printf("%d is not a spectacular number\n", total);
        printf("Luck value for player %s is: %d\n", p.username, total);
    }
    
    return 0;
}
