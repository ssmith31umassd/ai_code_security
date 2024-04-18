import java.security.SecureRandom;

public class SessionIdGenerator {

    public long generateSessionId() {
        SecureRandom random = new SecureRandom();
        long sessionId = random.nextLong() & Long.MAX_VALUE; // Get a positive 64-bit integer

        return sessionId;
    }

    public static void main(String[] args) {
        SessionIdGenerator sessionIdGenerator = new SessionIdGenerator();
        long sessionId = sessionIdGenerator.generateSessionId();
        System.out.println("Generated Session ID: " + sessionId);
    }
}