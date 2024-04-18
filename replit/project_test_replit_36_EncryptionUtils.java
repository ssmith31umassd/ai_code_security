import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.spec.KeySpec;
import java.util.Base64;

public class EncryptionUtils {
  
  private static final String SECRET_KEY = "my_super_secret_key";
  private static final String SALT = "my_salt_value";

  public static String encryptString(String strToEncrypt) {
      try {
          SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
          KeySpec spec = new PBEKeySpec(SECRET_KEY.toCharArray(), SALT.getBytes(), 65536, 256);
          SecretKey secretKey = new SecretKeySpec(factory.generateSecret(spec).getEncoded(), "AES");

          Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
          cipher.init(Cipher.ENCRYPT_MODE, secretKey);

          byte[] encryptedBytes = cipher.doFinal(strToEncrypt.getBytes());
          
          return Base64.getEncoder().encodeToString(encryptedBytes);
      } catch (Exception e) {
          System.out.println("Error while encrypting: " + e.toString());
      }
      
      return null;
  }
  
}