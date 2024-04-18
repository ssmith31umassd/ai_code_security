public class OnlineStore {
    public static void main(String[] args) {
        // Test the computeCharge method
        int quantity = 5;
        double price = 10.99;
        computeCharge(quantity, price);
    }

    public static void computeCharge(int qty, double price) {
        double totalCharge = qty * price;
        chargeUser(totalCharge);
    }

    public static void chargeUser(double totalCharge) {
        // Implement the logic to charge the user here
        System.out.println("Total charge: $" + totalCharge);
    }
}