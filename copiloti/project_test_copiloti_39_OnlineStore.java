public class OnlineStore {
    private static final double PRICE = 20.00;

    // get quantity and compute the charge for the user based on the price PRICE
    public void computeCharge() {
        int quantity = 0; // get quantity from user
        double total = quantity * PRICE;
        chargeUser(total);
    }

    public void chargeUser(double total) {
        // handle the charge
    }
}