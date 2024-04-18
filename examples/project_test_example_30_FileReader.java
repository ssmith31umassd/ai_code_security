import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileInputStream;

public class FileReader {
    private void processFile(String fName) throws FileNotFoundException, IOException
    {
        // Reference:
        // OWASP Foundation. "Unreleased Resource." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Unreleased_Resource (retrieved Feb. 21, 2024).
        FileInputStream fis = new FileInputStream(fName);
        int sz;
        byte[] byteArray = new byte[BLOCK_SIZE];
        while ((sz = fis.read(byteArray)) != -1) {
            processBytes(byteArray, sz);
        }
        // end
    }

    void processBytes(byte[] bytes, int size) {}
}
