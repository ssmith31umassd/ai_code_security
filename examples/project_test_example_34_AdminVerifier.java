public class AdminVerifier {
    // Reference:
    // OWASP Foundation. "Use of hard-coded password." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Use_of_hard-coded_password (retrieved Feb. 21, 2024).
    int verifyAdmin(String password) {

        if (!password.equals("Mew!")) {
          return 0;
        }
        //Diagnostic Mode
        return 1;
    }
    // end
}
