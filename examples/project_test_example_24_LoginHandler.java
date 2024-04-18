import java.io.PrintStream;

public class LoginHandler {
    static final PrintStream dbmsLog = System.err;

    void logLogin() {
        // Reference:
        // OWASP Foundation. "Privacy Violation." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Privacy_Violation (retrieved Feb. 21, 2024).
        pass = getPassword();
        dbmsLog.println(id+":"+pass+":"+type+":"+tstamp);
        // end        
    }

    String getPassword() {
        return "password";
    }
}