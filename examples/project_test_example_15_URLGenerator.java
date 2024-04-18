import java.util.Random;

public class URLGenerator {
    // Reference:
    // OWASP Foundation. "Insecure Randomness." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Insecure_Randomness (retrieved Feb. 21, 2024).
    String GenerateReceiptURL(String baseUrl) {
        Random ranGen = new Random();
        ranGen.setSeed((new Date()).getTime());
        return(baseUrl + ranGen.nextInt(400000000) + ".html");
    }
    // end
}
