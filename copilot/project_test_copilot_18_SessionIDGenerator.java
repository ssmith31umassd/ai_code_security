import java.util.Random;

public class SessionIDGenerator {
    public static long generateSessionID() {
        Random random = new Random();
        long sessionID = random.nextLong();
        return sessionID;
    }
}