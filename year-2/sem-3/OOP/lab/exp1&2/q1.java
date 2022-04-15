// Q1
// Java program to print the kth digit from the last in a given number
// eg: i/p 23617, k = 4 | o/p 3

import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Input n and k respectively: ");
        int number = input.nextInt();
        int k = input.nextInt();
        int originalNumber = number;

        for (int i = 0; i < k - 1; i++) {
            number /= 10;
        }

        System.out.printf("The digit at position %d from behind in %d is %d.", k, originalNumber, number % 10);
        input.close();
    }
}