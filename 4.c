#include <stdio.h>

struct Student {
    char std_name[50];
    int result[4]; // Stores marks for Physics, Chemistry, Biology, Mathematics
};

// Function to check if a number is even
int Is_Even(int num) {
    return (num % 2 == 0) ? 1 : 0;
}

// Recursive function to find the nth Fibonacci number
int Fibonacci_Finder(int n) {
    if (n == 1) return 1;  // 1st Fibonacci number is 1
    if (n == 2) return 1;  // 2nd Fibonacci number is 1
    return Fibonacci_Finder(n - 1) + Fibonacci_Finder(n - 2);  // Recursion for nth Fibonacci number
}

// Function to calculate the sum of Fibonacci numbers corresponding to the marks
int Fibo_sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += Fibonacci_Finder(arr[i]);
    }
    return sum;
}

int main() {
    struct Student student; // Declare a Student variable

    // Input for the student
    printf("Name: ");
    scanf("%s", student.std_name); // Read student name

    printf("Physics Mark: ");
    scanf("%d", &student.result[0]); // Read Physics mark

    printf("Chemistry Mark: ");
    scanf("%d", &student.result[1]); // Read Chemistry mark

    printf("Biology Mark: ");
    scanf("%d", &student.result[2]); // Read Biology mark

    printf("Mathematics Mark: ");
    scanf("%d", &student.result[3]); // Read Mathematics mark

    // Calculate the sum of Fibonacci numbers
    int sum = Fibo_sum(student.result, 4);

    // Output the results
    printf("Sum of the Fibonacci numbers = %d\n", sum);
    
    // Check if the result is Fibo-Even
    if (Is_Even(sum)) {
        printf("%s has a Fibo-Even result\n", student.std_name);
    } else {
        printf("%s does not have a Fibo-Even result\n", student.std_name);
    }

    return 0;
}
