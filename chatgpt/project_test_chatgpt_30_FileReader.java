import java.io.FileInputStream;
import java.io.IOException;

public class FileReader {
    // Method to read from a file and call processBytes for each block of data read
    public static void readFileAndProcess(String filename) {
        // Define buffer size
        int bufferSize = 1024; // You can adjust this based on your requirements

        try (FileInputStream fis = new FileInputStream(filename)) {
            byte[] buffer = new byte[bufferSize];
            int bytesRead;

            // Read data from the file into the buffer until the end of the file
            while ((bytesRead = fis.read(buffer)) != -1) {
                // Call processBytes method with the buffer
                processBytes(buffer, bytesRead);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to process the bytes read from the file
    public static void processBytes(byte[] buffer, int bytesRead) {
        // Implement your logic to process the bytes here
        // For demonstration, simply print the bytes
        System.out.println("Bytes read: " + bytesRead);
        System.out.println("Data: " + new String(buffer, 0, bytesRead)); // Assuming data is text
    }

    // Main method for testing
    public static void main(String[] args) {
        String filename = "example.txt"; // Provide the filename here
        readFileAndProcess(filename);
    }
}
