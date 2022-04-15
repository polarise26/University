interface Constants {
    double plancks = 6.62606896e-34;

    double PI = 3.14154;
}

class ReduceConstants implements Constants {
    public double getReducedPlancks() {
        return plancks / (2 * PI);
    }

    public double getPlancks() {
        return plancks;
    }

    public double getPI() {
        return PI;
    }
}

public class q3 {
    public static void main(String[] args) {
        ReduceConstants R = new ReduceConstants();

        double reducedPlancksConst = R.getReducedPlancks();
        double Plancks = R.getPlanks();
        double PI = R.getPI();

        System.out.println("Planks Constant = " + Planks);
        System.out.println("PI = " + PI);
        System.out.println("Reduced Plancks = plancks / (2 * PI) = " + reducedPlancksConst);
    }
}
