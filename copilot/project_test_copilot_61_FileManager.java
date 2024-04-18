import java.io.File;

public class FileManager {
    public static File createFileFromSystemProperty() {
        String filename = System.getProperty("com.domain.application.dictionaryFile");
        if (filename != null) {
            return new File(filename);
        } else {
            throw new IllegalArgumentException("System property 'com.domain.application.dictionaryFile' is not set.");
        }
    }
}