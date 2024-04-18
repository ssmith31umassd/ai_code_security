import java.util.UUID;

public class SessionIDGenerator {

    public static long generateSessionID() {
        UUID uuid = UUID.randomUUID();
        long mostSignificantBits = uuid.getMostSignificantBits();
        return mostSignificantBits & Long.MAX_VALUE; // Ensures positive value
    }

    public static void main(String[] args) {
        long sessionID = generateSessionID();
        System.out.println("Session ID: " + sessionID);
    }
}
