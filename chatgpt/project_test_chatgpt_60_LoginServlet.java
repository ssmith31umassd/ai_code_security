import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Get username and password from the request
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Validate username and password (You may perform additional validation here)

        // For demonstration purposes, let's just print the username and password
        System.out.println("Username: " + username);
        System.out.println("Password: " + password);

        // You can further process the username and password, e.g., authenticate against a database

        // Redirect to appropriate page based on authentication result
        if (authenticated(username, password)) {
            // Redirect to user home page
            response.sendRedirect("user_home.jsp");
        } else {
            // Redirect back to login page with error message
            response.sendRedirect("login.jsp?error=1");
        }
    }

    // Dummy authentication method (Replace with your actual authentication logic)
    private boolean authenticated(String username, String password) {
        // Dummy authentication logic (always return true for demonstration)
        return true;
    }
}
