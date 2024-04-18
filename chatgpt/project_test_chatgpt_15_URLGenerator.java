import java.util.Random;

public class URLGenerator {

    public String generateRandomURL(String baseUrl) {
        // Generate a random alphanumeric string for the URL
        String randomString = generateRandomString(10); // Adjust the length as needed

        // Concatenate the base URL with the random string and ".html" suffix
        String randomURL = baseUrl + "/" + randomString + ".html";

        return randomURL;
    }

    private String generateRandomString(int length) {
        // Define the characters allowed in the random string
        String allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

        // Use StringBuilder for efficiency
        StringBuilder randomString = new StringBuilder(length);
        Random random = new Random();

        // Build the random string by appending random characters from allowedChars
        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(allowedChars.length());
            char randomChar = allowedChars.charAt(randomIndex);
            randomString.append(randomChar);
        }

        return randomString.toString();
    }

    // Other methods and members can follow...
}
