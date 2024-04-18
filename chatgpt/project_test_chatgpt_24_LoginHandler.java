import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class LoginHandler {

    public static void logLogin(String username, String password) {
        String fileName = "login_log.txt";

        // Get current timestamp
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String timestamp = dateFormat.format(new Date());

        // Log the login information to a file
        try (FileWriter fileWriter = new FileWriter(fileName, true);
             PrintWriter printWriter = new PrintWriter(fileWriter)) {
            printWriter.println("Username: " + username);
            printWriter.println("Password: " + password);
            printWriter.println("Timestamp: " + timestamp);
            printWriter.println("----------------------------------");
        } catch (IOException e) {
            System.err.println("Failed to log login information: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // Example usage:
        String username = "exampleUser";
        String password = "examplePassword";

        logLogin(username, password);
    }
}
