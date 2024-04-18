import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class UserLoginHandler {

    public void handleUserLogin(String username, String password) {
        String logFileName = "login_logs.txt";
        String logMessage = String.format("Username: %s, Password: %s, Timestamp: %s",
                username, password, getCurrentTimestamp());

        try (PrintWriter writer = new PrintWriter(new FileWriter(logFileName, true))) {
            writer.println(logMessage);
            System.out.println("Login information logged successfully");
        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }
    }

    private String getCurrentTimestamp() {
        LocalDateTime currentTime = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return formatter.format(currentTime);
    }

    public static void main(String[] args) {
        UserLoginHandler loginHandler = new UserLoginHandler();
        String username = "john_doe";
        String password = "secretpassword";
        
        loginHandler.handleUserLogin(username, password);
    }
}