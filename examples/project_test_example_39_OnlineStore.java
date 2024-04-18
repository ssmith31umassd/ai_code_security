public class OnlineStore {
    void computeCharge() {
        // Reference:
        // MITRE. "CWE-20: Improper Input Validation." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/20.html (retrieved Feb. 22, 2024).
        final double price = 20.00;
        int quantity = getQuantity();
        double total = price * quantity;
        chargeUser(total);
        // end
    }

    void chargeUser(double amount) {}

    int getQuantity() {
       //         int quantity = currentUser.getAttribute("quantity");
       return 1; 
    }
}
