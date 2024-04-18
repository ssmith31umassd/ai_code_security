import java.io.File;

public class FileManager {
    public static File getDictionaryFile() {
        // Get the filename specified in the System property
        String filename = System.getProperty("com.domain.application.dictionaryFile");

        // Check if the filename is specified
        if (filename == null || filename.isEmpty()) {
            // Handle the case when the filename is not specified
            throw new IllegalArgumentException("Dictionary file not specified in system property.");
        }

        // Create a File object using the specified filename
        File file = new File(filename);

        // Return the File object
        return file;
    }

    public static void main(String[] args) {
        // Example usage:
        try {
            File dictionaryFile = FileManager.getDictionaryFile();
            System.out.println("Dictionary File: " + dictionaryFile.getAbsolutePath());
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
