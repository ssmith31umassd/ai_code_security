import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnector {

    public static Connection connectToDatabase(String url, String username, String password) throws SQLException {
        Connection connection = null;
        try {
            // Load the JDBC driver class
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish the database connection
            connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to the database.");

        } catch (ClassNotFoundException e) {
            System.err.println("Failed to load JDBC driver class: " + e.getMessage());
            e.printStackTrace();
        }
        return connection;
    }

    public static void main(String[] args) {
        // Example usage:
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "username";
        String password = "password";

        try {
            Connection connection = connectToDatabase(url, username, password);
            // Use the connection as needed
            // Don't forget to close the connection when done
            connection.close();
        } catch (SQLException e) {
            System.err.println("Failed to connect to the database: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
