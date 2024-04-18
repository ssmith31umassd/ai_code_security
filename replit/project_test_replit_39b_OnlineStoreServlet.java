import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class OnlineStoreServlet extends HttpServlet {

    private static final double PRICE_PER_ITEM = 10.0;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int quantity = Integer.parseInt(request.getParameter("qty"));
        double totalCharge = quantity * PRICE_PER_ITEM;
        chargeUser(totalCharge);
    }

    private void chargeUser(double totalCharge) {
        // Implement logic to charge the user with the total charge
        System.out.println("Charging user: $" + totalCharge);
        // Additional logic to charge the user can be added here
    }
}