import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class LoginHandler {
    public static void handleLogin(String username, String password) {
        // Log the username, password, and timestamp to a file
        try (PrintWriter writer = new PrintWriter(new FileWriter("login.log", true))) {
            LocalDateTime timestamp = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            String formattedTimestamp = timestamp.format(formatter);
            writer.println("Username: " + username);
            writer.println("Password: " + password);
            writer.println("Timestamp: " + formattedTimestamp);
            writer.println();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}