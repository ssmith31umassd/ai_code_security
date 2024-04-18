public class OnlineStore {

    // Assume chargeUser method is defined somewhere in this class
    public void chargeUser(double totalCharge) {
        // Implementation of chargeUser method
    }

    public void computeCharge(int qty, double price) {
        if (qty < 0 || price < 0) {
            throw new IllegalArgumentException("Quantity and price must be non-negative.");
        }

        double totalCharge = qty * price;
        chargeUser(totalCharge);
    }
}