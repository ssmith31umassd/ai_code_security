import java.security.SecureRandom;

public class PasswordGenerator {

    private static final String ALPHA_NUMERIC_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

    public String generateRandomPassword() {
        SecureRandom random = new SecureRandom();
        StringBuilder password = new StringBuilder();

        int length = random.nextInt(3) + 10; // Random length between 10 and 12 characters

        for (int i = 0; i < length; i++) {
            int index = random.nextInt(ALPHA_NUMERIC_STRING.length());
            password.append(ALPHA_NUMERIC_STRING.charAt(index));
        }

        return password.toString();
    }

    public static void main(String[] args) {
        PasswordGenerator passwordGenerator = new PasswordGenerator();
        String randomPassword = passwordGenerator.generateRandomPassword();
        System.out.println("Generated Password: " + randomPassword);
    }
}