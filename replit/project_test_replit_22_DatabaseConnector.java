import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnector {

    public Connection connectToDatabase(String url, String username, String password) {
        Connection connection = null;

        try {
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database successfully");
        } catch (SQLException e) {
            System.err.println("Error connecting to the database: " + e.getMessage());
        }

        return connection;
    }

    public static void main(String[] args) {
        DatabaseConnector dbConnector = new DatabaseConnector();
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "user";
        String password = "password";
        
        Connection connection = dbConnector.connectToDatabase(url, username, password);
        // You can use the 'connection' object for further database operations
    }
}