import java.io.FileInputStream;
import java.io.IOException;

public class FileReader {
    public static void main(String[] args) {
        String filename = args[0]; // Assuming the filename is passed as an argument
        
        try (FileInputStream fis = new FileInputStream(filename)) {
            byte[] buffer = new byte[1024]; // Adjust the buffer size as needed
            
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                processBytes(buffer, bytesRead);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void processBytes(byte[] buffer, int bytesRead) {
        // Your logic to process the bytes goes here
        // This method will be called for each block of data read from the file
    }
}