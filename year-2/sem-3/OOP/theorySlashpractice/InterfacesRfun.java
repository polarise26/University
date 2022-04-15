import java.util.Scanner;

import javax.sound.sampled.SourceDataLine;

interface chips {
    String brand = "Doritos";

    void openBag();

    void eatChips();

    void getNew();
}

public class InterfacesRfun implements chips {

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);

        System.out.print("The brand is: ");
        System.out.println(brand);
        int stop = 0;
        while (stop == 0) {
            System.out.println(
                    "Would you like to: 1. Open the bag? 2. Eat the chips? 3. Get a new bag? 4. Stop eating chips?");
            int choice = ip.nextInt();
            InterfacesRfun example = new InterfacesRfun();
            if (choice == 1) {
                example.openBag();
            } else if (choice == 2) {
                example.eatChips();
            } else if (choice == 3) {
                example.getNew();
            } else if (choice == 4) {
                stop = 1;
            } else {
                System.out.println("Invalid input.");
            }

        }
        System.out.println("You've stopped eating chips");
        ip.close();
    }

    @Override
    public void openBag() {
        System.out.println("Bag opened.");
    }

    @Override
    public void eatChips() {
        System.out.println("You ate chips.");
    }

    @Override
    public void getNew() {
        System.out.println("New bag has arrived.");
    }
}