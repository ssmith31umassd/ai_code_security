public class OnlineStoreServlet {
    private static final double PRICE = 20.00;

    public void chargeUser(double total) {
        // handle the charge
    }

    // get quantity from HTTP request, then compute the total and charge the user
    public void computeCharge() {
        int quantity = 0; // get quantity from HTTP request
        double total = quantity * PRICE;
        chargeUser(total);
    }
}