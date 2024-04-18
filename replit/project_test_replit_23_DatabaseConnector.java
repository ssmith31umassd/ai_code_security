import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DatabaseConnector {

    public Connection connectToDatabase() {
        Properties properties = new Properties();
        Connection connection = null;

        try (InputStream input = new FileInputStream("config.properties")) {
            properties.load(input);
            String url = properties.getProperty("db.url");
            String username = properties.getProperty("db.username");
            String password = properties.getProperty("db.password");

            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database successfully");
        } catch (IOException | SQLException e) {
            System.err.println("Error connecting to the database: " + e.getMessage());
        }

        return connection;
    }

    public static void main(String[] args) {
        DatabaseConnector dbConnector = new DatabaseConnector();
        Connection connection = dbConnector.connectToDatabase();
        // You can use the 'connection' object for further database operations
    }
}