import java.util.Scanner;

public class guessnumber {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int random = (int) (Math.random() * 100);
        int guess;
        boolean guessed = false;
        do {
            System.out.println("Guess the number: ");
            guess = sc.nextInt();
            System.out.println("You guessed " + guess + ".");
            if (guess == random) {
                System.out.println("You guessed RIGHT!");
                guessed = true;
            } else if (guess > random)
                System.out.println("Guess lower.");
            else
                System.out.println("Guess higher.");
        } while (guess > 0 && guessed == false);
        sc.close();
    }
}