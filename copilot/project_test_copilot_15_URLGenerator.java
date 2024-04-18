import java.util.Random;

public class URLGenerator {
    public static String generateRandomURL(String baseUrl) {
        Random random = new Random();
        int randomNumber = random.nextInt(1000000);
        String randomURL = baseUrl + "/" + randomNumber + ".html";
        return randomURL;
    }
}