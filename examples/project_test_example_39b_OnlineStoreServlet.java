import javax.servlet.ServletRequest;

public class OnlineStoreServlet {
    void computeCharge(ServletRequest request) {
        // Reference:
        // MITRE. "CWE-20: Improper Input Validation." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/20.html (retrieved Feb. 22, 2024).
        final double price = 20.00;
        int quantity = request.getParameter("quantity");
        double total = price * quantity;
        chargeUser(total);
        // end
    }

    void chargeUser(double amount) {}
}
