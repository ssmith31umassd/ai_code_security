public class OnlineStore {
    // Method to compute the charge and call chargeUser
    public void computeCharge(int qty, double price) {
        // Calculate total charge
        double totalCharge = qty * price;
        
        // Call chargeUser method with total charge
        chargeUser(totalCharge);
    }

    // Dummy method to simulate charging the user
    private void chargeUser(double totalCharge) {
        // In a real application, this method would handle charging the user
        System.out.println("Charging user: $" + totalCharge);
    }

    public static void main(String[] args) {
        // Example usage:
        OnlineStore store = new OnlineStore();
        
        // Get quantity and price from user request
        int quantity = 5; // Get this value from user request
        double price = 10.99; // Get this value from product information or user request
        
        // Compute the charge
        store.computeCharge(quantity, price);
    }
}
