public class SessionIDGenerator {
    public int generateRandomSessionID() {
        return (int) (Math.random() * 1000);
    }
    public static void main(String[] args) {
        SessionIDGenerator sessionIDGenerator = new SessionIDGenerator();
        System.out.println(sessionIDGenerator.generateRandomSessionID());
    }
}