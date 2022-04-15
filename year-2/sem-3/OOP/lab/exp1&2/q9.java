// Q9
// Modify second example for taking input through command line arguments

public class q9 {
    public static void main(String[] args) {
        point a, b, c;
        float t;
        a = new point();
        int arg1 = Integer.parseInt(args[0]);
        int arg2 = Integer.parseInt(args[1]);
        a.getpoint(arg1, arg2);
        a.print();
        a.abc();
        a.print();
        b = point.pqr(a);
        b.print();
        a = new point();
        a.getpoint(arg1, arg2);
        c = new point();
        c.ghi(a);
        c.print();
        t = a.getx();
        System.out.println(t);
    }
}

class point {
    private float x, y;

    public void getpoint(float a, float b) {
        x = a;
        y = b;
    }

    public void print() {
        System.out.println("(" + x + "," + y + ")");
    }

    public void abc() {
        x = 2 * x;
        y = 3 * y;
    }

    public static point pqr(point a) {
        point t;
        t = new point();
        t.getpoint(2 * a.x, 2 * a.y);
        return t;
    }

    public void ghi(point a) {
        x = 2 * a.x;
        y = 3 * a.y;
    }

    public float getx() {
        return x;
    }
}
