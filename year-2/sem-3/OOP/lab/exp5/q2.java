import java.util.*;

interface A {
    void meth1();

    void meth2();
}

class MyClass implements A {
    private int x;

    public MyClass(int a) {
        x = a;
    }

    public void printData() {
        System.out.println("X: " + x);
    }

    public void meth1() {
        System.out.println("Square = " + Math.pow(x, 2));
    }

    public void meth2() {
        System.out.println("Cube = " + Math.pow(x, 3));
    }
}

public class q2 {
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter a number to get its square and cube: ");
        int n = ip.nextInt();
        MyClass M = new MyClass(n);
        M.printData();
        M.meth1();
        M.meth2();
        ip.close();
    }
}
