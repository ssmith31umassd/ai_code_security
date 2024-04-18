import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class OnlineStoreServlet extends HttpServlet {

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

    // Override doGet method to handle GET requests
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        // Get quantity from the HTTP parameter "qty"
        int quantity = Integer.parseInt(req.getParameter("qty"));

        // Get price (assuming a constant price in this example)
        double price = 10.99; // Get this value from product information or user request

        // Compute the charge
        computeCharge(quantity, price);
    }
}
