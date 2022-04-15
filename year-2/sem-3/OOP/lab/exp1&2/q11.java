// Q11
// Define fb. If point p is (x,y) then p.fb() will make it (2x,x+y). (20,4) (40,24)Define fc. If point p is (x,y) then p.fc() will make it (x+y,x*y). (20,4) (24,80)

public class q11 {
    public static void main(String[] args) {
        point p;
        p = new point();

        int arg1 = Integer.parseInt(args[0]);
        int arg2 = Integer.parseInt(args[1]);

        p.getpoint(arg1, arg2);
        p.print();

        p.fb(arg1, arg2);
        p.print();

        p.fc(arg1, arg2);
        p.print();
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

    public void fb(int x, int y) {
        this.x = 2 * x;
        this.y = x + y;
    }

    public void fc(int x, int y) {
        this.x = x + y;
        this.y = x * y;
    }
}
