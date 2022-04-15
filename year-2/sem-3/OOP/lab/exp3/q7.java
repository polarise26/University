// Q7
// Write a set of overloaded functions max() that returns the biggest of two numbers passed to them as arguments. Make versions for int and float.

import java.util.*;

public class q7 {
    public static int max(int x, int y) {
        System.out.println("Returning max of int type");
        return x > y ? x : y;
    }

    public static float max(float x, float y) {
        System.out.println("Returning max of float type");
        return x > y ? x : y;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int x, y;
        float a, b;

        System.out.println("Enter two int numbers: ");
        x = input.nextInt();
        y = input.nextInt();

        System.out.println(max(x, y));

        System.out.println("Enter two float numbers: ");
        a = input.nextFloat();
        b = input.nextFloat();

        System.out.println(max(a, b));

        input.close();
    }

}