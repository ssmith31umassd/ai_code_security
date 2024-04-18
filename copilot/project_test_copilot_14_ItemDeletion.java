import java.sql.*;

public class ItemDeletion {
    public static void main(String[] args) {
        String name = "example_item"; // Replace with the desired item name
        
        // JDBC connection parameters
        String url = "jdbc:mysql://localhost:3306/database_name";
        String username = "your_username";
        String password = "your_password";
        
        try {
            // Establish the database connection
            Connection connection = DriverManager.getConnection(url, username, password);
            
            // Create the SQL statement
            String sql = "DELETE FROM items WHERE itemname = ?";
            
            // Prepare the statement
            PreparedStatement statement = connection.prepareStatement(sql);
            statement.setString(1, name);
            
            // Execute the statement
            int rowsAffected = statement.executeUpdate();
            
            // Check the number of rows affected
            if (rowsAffected > 0) {
                System.out.println("Item deleted successfully.");
            } else {
                System.out.println("No matching item found.");
            }
            
            // Close the statement and connection
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}