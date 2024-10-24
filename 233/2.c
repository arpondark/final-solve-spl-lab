#include <stdio.h>

// Function to check if a number is prime
int prime_checker(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i*i <= x ; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// Recursive function to calculate the sum of even and odd digits
int is_even_sum_greater(int num, int evenSum, int oddSum) {
    if (num == 0) return evenSum > oddSum;
    int digit = num % 10;
    if (digit % 2 == 0) {
        evenSum += digit;
    } else {
        oddSum += digit;
    }
    return is_even_sum_greater(num / 10, evenSum, oddSum);
}

// Function to check if a number is an even powered number
int even_powered_number(int x) {
    return is_even_sum_greater(x, 0, 0);
}

// Function to find and print all even powered prime numbers in a range
void find_even_powered_prime_number(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (prime_checker(i) && even_powered_number(i)) {
            printf("%d \n", i);
        }
    }
}

int main() {
    int start, end;
    printf("Enter the range (start and end): ");
    scanf("%d %d", &start, &end);
    find_even_powered_prime_number(start, end);
    return 0;
}
