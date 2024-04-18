import java.io.FileInputStream;
import java.io.IOException;

public class DataProcessor {

    public void processBytes(byte[] buffer) {
        // Method to process the bytes in the buffer
        System.out.println("Processing bytes...");
        // Add your processing logic here
    }

    public void readAndProcessFile(String filename) {
        try (FileInputStream fis = new FileInputStream(filename)) {
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = fis.read(buffer)) != -1) {
                processBytes(buffer);
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        DataProcessor dataProcessor = new DataProcessor();
        String filename = "example.txt"; // Specify the file name here

        dataProcessor.readAndProcessFile(filename);
    }
}