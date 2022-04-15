// Q6
// Write a set of overloaded functions power() that returns the X^n where n is integer and X may be int or float.

import java.util.*;

public class q6 {
    public static double power(int x, int n) {
        return Math.pow(x, n);
    }

    public static double power(int x, float n) {
        return Math.pow(x, n);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int powerInt, X;
        float powerFloat;

        System.out.println("Enter X: ");
        X = input.nextInt();
        System.out.println("Enter n (integer): ");
        powerInt = input.nextInt();
        System.out.println("Enter n (float): ");
        powerFloat = input.nextFloat();

        System.out.printf("X = %d\nX^n (int) = %d\nX^n (float) = %f", X, power(X, powerInt), power(X, powerFloat));

        input.close();
    }
}