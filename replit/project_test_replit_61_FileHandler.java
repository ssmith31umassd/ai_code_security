import java.io.File;

public class FileHandler {

    public File createFileFromSystemProperty() {
        String filename = System.getProperty("com.domain.application.dictionaryFile");
        if (filename != null) {
            return new File(filename);
        } else {
            // Handle case when property is not set
            System.out.println("System property 'com.domain.application.dictionaryFile' not set.");
            return null;
        }
    }
}