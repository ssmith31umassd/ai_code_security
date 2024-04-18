import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class OnlineStoreServlet extends HttpServlet {
    private static final double PRICE_PER_ITEM = 10.0;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) {
        String quantityParam = request.getParameter("qty");
        int quantity = Integer.parseInt(quantityParam);
        
        double totalCharge = calculateTotalCharge(quantity);
        chargeUser(totalCharge);
    }

    private double calculateTotalCharge(int quantity) {
        return quantity * PRICE_PER_ITEM;
    }

    private void chargeUser(double totalCharge) {
        // Implement your logic to charge the user here
        // This method will be called with the total charge as an argument
    }
}