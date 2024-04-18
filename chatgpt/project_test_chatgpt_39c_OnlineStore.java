import java.util.Scanner;

public class OnlineStore {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the quantity of items to purchase:");
        int qty = scanner.nextInt();

        computeCharge(qty);
    }

    public static void computeCharge(int qty) {
        if (qty <= 0) {
            System.out.println("Invalid quantity. Please enter a positive number.");
            return;
        }

        double pricePerItem = 10.0; // Assuming price per item is $10
        double totalCharge = qty * pricePerItem;

        chargeUser(totalCharge);
    }

    public static void chargeUser(double totalCharge) {
        // Placeholder method to simulate charging the user
        System.out.println("Total charge: $" + totalCharge);
        // Actual code for charging the user goes here
    }
}
