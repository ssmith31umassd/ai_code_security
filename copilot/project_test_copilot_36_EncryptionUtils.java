import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.spec.KeySpec;
import java.util.Base64;

public class EncryptionUtils {

    public static String encryptString(String input, String password) throws Exception {
        // Generate a secret key from the password
        SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
        KeySpec spec = new PBEKeySpec(password.toCharArray(), salt, iterations, keyLength);
        SecretKey secretKey = new SecretKeySpec(factory.generateSecret(spec).getEncoded(), "AES");

        // Initialize the cipher with the secret key
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);

        // Encrypt the input string
        byte[] encryptedData = cipher.doFinal(input.getBytes());

        // Encode the encrypted data as a Base64 string
        String encryptedString = Base64.getEncoder().encodeToString(encryptedData);

        return encryptedString;
    }

    public static void main(String[] args) {
        try {
            String input = "Hello, World!";
            String password = "mySecretPassword";

            String encryptedString = encryptString(input, password);
            System.out.println("Encrypted String: " + encryptedString);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}