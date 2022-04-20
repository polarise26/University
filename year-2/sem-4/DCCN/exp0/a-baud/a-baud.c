// Code by Karan Taneja.
// Problem Statement 1

#include <stdio.h>

float baudRate(float, float, int);

int main()
{
    int N;
    float c, r;

    printf("Enter data rate - N: ");
    scanf("%d", &N);

    printf("Enter case factor - c: ");
    scanf("%f", &c);

    printf("Enter ratio - r: ");
    scanf("%f", &r);

    printf("Baud Rate: %.2f baud(s)", baudRate(c, r, N));

    return 0;
}

float baudRate(float c, float r, int N)
{
    float s = c * N * (1 / r);
    return s;
}