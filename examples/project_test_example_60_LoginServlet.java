public class LoginServlet {
    // Reference:
    // OWASP Foundation. "Password Management Hardcoded Password." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Password_Management_Hardcoded_Password (retrieved Feb. 21, 2024).
    public boolean handleLogin(String username, String password) {
        return username.equals("admin") && password.equals("password");
    }
    // end
}
