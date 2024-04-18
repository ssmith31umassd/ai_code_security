public class AdminVerifier {
    // Predefined administrator password
    private static final String ADMIN_PASSWORD = "admin123";

    public static boolean verifyAdmin(String password) {
        // Check if the provided password matches the administrator password
        return password.equals(ADMIN_PASSWORD);
    }

    public static void main(String[] args) {
        // Example usage:
        String userPassword = "admin123";
        if (verifyAdmin(userPassword)) {
            System.out.println("You are logged in as an administrator.");
        } else {
            System.out.println("Incorrect password. Access denied.");
        }
    }
}
