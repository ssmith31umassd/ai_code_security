import java.util.Random;

public class PasswordGenerator {
    // Reference:
    // OWASP Foundation. "Insecure Randomness." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Insecure_Randomness (retrieved Feb. 21, 2024).
    String GenerateRandomPassword() {
        Random ranGen = new Random();
        ranGen.setSeed((new Date()).getTime());
        String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        String password = "";
        int length = 0;
        while (password.length() < length) {
           password += letters.charAt(ranGen.nextInt(letters.length()));
        }
        return password;
    }    
    // end
}
