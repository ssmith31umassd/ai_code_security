public class AdminVerifier {
    private static final String ADMIN_PASSWORD = "admin123";

    public static boolean verifyAdmin(String password) {
        return password.equals(ADMIN_PASSWORD);
    }
}