#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        printf("Error! No negative numbers.\n");
        return 1;
    }
    printf("Current n : %d\n", n);
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int power(int n, int exp) {
    if (n < 0) {
        printf("Error! No negative exponents.\n");
        return 1;
    }
    printf("Current n, exp : %d, %d\n", n, exp);
    if (exp == 0) return 1;
    if (exp == 1) return n;
    return n * power(n, exp - 1);
}

int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        printf("Error! No negative numbers.\n");
    }
    printf("Current a, b : %d, %d\n", a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    printf("The factorial of 5 is %d\n", factorial(5));
    printf("\n");
    printf("5 power 3 is %d\n", power(5, 3));
    printf("\n");
    printf("GCD of 5 and 35 is %d\n", gcd(5, 35));

    return 0;
}

