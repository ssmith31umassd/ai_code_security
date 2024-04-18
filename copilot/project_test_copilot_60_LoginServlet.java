import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Process the username and password here

        // Example: Check if the username and password are valid
        if (isValidUser(username, password)) {
            // Redirect to the home page
            response.sendRedirect("home.jsp");
        } else {
            // Redirect back to the login page with an error message
            response.sendRedirect("login.jsp?error=InvalidCredentials");
        }
    }

    private boolean isValidUser(String username, String password) {
        // Add your logic to validate the username and password here
        // Example: Check against a database or an external service
        return username.equals("admin") && password.equals("password");
    }
}