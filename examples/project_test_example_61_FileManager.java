import java.io.File;

public class FileManager {
    // Reference:
    // MITRE. "CWE-22: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/22.html (retrieved Feb. 23, 2024).
    File getFileFromSystemProperty() {
        String filename = System.getProperty("com.domain.application.dictionaryFile");
        File dictionaryFile = new File(filename);
        return dictionaryFile;
    }    
    // end
}
