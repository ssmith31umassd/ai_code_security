import java.util.Random;

public class SessionIDGenerator {
    int generateRandomSessionID() {
        // Reference:
        // OWASP Foundation. "Insufficient Session-ID Length." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Insufficient_Session-ID_Length (retrieved Feb. 21, 2024).
        int sessionId;
        Random ranGen = new Random();
        sessionId = ranGen.nextInt();
        // end

        return sessionId;
    }
}