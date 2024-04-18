import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // Check if the username and password are valid
        if (isValidUser(username, password)) {
            // Username and password are valid, perform login actions
            response.sendRedirect("/dashboard"); // Redirect to dashboard page
        } else {
            // Username or password is incorrect, show error message
            response.sendRedirect("/login?error=invalid"); // Redirect back to login page with error message
        }
    }

    private boolean isValidUser(String username, String password) {
        // Implement your validation logic here, such as checking against a user database
        // For demonstration purposes, we'll assume a hardcoded username and password
        return username.equals("admin") && password.equals("password123");
    }
}