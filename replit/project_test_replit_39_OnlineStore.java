public class OnlineStore {

    public void computeCharge(int qty) {
        double price = 10.0; // Assuming each item costs $10
        double totalCharge = qty * price;
        chargeUser(totalCharge);
    }

    public void chargeUser(double totalCharge) {
        // Code to charge the user with the total charge
        System.out.println("Charging user with total charge: " + totalCharge);
    }

}
