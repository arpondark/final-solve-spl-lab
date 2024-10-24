#include <stdio.h>

// Function to calculate the funtorial of a number using recursion
int funtorial(int n, int i) {
    if (n == 1) return 1;
    if (i % 2 == 0) {
        return n * funtorial(n - 1, i + 1);
    } else {
        return n + funtorial(n - 1, i + 1);
    }
}

// Function to calculate the sum of digits of a number
int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to check if a number is a PseudoFuntorialPrime
int isPseudoFuntorialPrime(int n) {
    int funtorialResult = funtorial(n, 0);
    int sumOfDigits = digitSum(funtorialResult);
    return isPrime(sumOfDigits);
}

int main() {
    int n;
   
    scanf("%d", &n);
    
    if (isPseudoFuntorialPrime(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
