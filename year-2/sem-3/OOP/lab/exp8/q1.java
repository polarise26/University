import java.io.*;
import java.lang.*;

class kapil {
    public static void main(String args[]) {
        String a, b;
        try {
            DataInputStream o = new DataInputStream(System.in);
            a = o.readLine();
            b = a.substring(2, 5);
            System.out.println(b);
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}