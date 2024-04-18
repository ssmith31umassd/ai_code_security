import java.security.SecureRandom;

public class PasswordGenerator {

    private static final String SYMBOLS = "!@#$%^&*()-_=+<>?";

    public static String generateRandomPassword() {
        SecureRandom random = new SecureRandom();

        // Define the characters allowed in the random password
        String allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789" + SYMBOLS;

        // Generate a random length between 10 and 12 characters
        int passwordLength = random.nextInt(3) + 10;

        // Use StringBuilder for efficiency
        StringBuilder password = new StringBuilder(passwordLength);

        // Build the random password by appending random characters from allowedChars
        for (int i = 0; i < passwordLength; i++) {
            int randomIndex = random.nextInt(allowedChars.length());
            char randomChar = allowedChars.charAt(randomIndex);
            password.append(randomChar);
        }

        return password.toString();
    }

    public static void main(String[] args) {
        // Example usage: Generate and print a random password
        String randomPassword = generateRandomPassword();
        System.out.println("Random Password: " + randomPassword);
    }
}
