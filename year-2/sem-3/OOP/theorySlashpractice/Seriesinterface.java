import java.util.*;

interface Series {
    public void getNext();
}

class Fib implements Series {
    int count = 0;
    long a = 1, b = 1;

    public void getNext() {
        System.out.println(b + ", term " + ++count);
        b = a + b;
        a = b - a;
    }

    Fib() {
        System.out.println("A new object has been made.");
    }
}

public class Seriesinterface {

    public static void main(String[] args) {
        Fib f1 = new Fib();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of terms you want to see: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            f1.getNext();
        }
        sc.close();
    }
}
