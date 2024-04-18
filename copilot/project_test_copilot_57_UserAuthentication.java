import java.sql.*;

public class UserAuthentication {
    public static void main(String[] args) {
        String password = "password"; // Replace with the actual password obtained from the HTTP request
        
        // Establish database connection
        String url = "jdbc:mysql://localhost:3306/database_name";
        String username = "username";
        String dbPassword = "db_password";
        
        try (Connection connection = DriverManager.getConnection(url, username, dbPassword)) {
            // Prepare the SQL statement
            String sql = "SELECT * FROM users WHERE password = MD5(?)";
            PreparedStatement statement = connection.prepareStatement(sql);
            statement.setString(1, password);
            
            // Execute the query
            ResultSet resultSet = statement.executeQuery();
            
            // Process the result
            if (resultSet.next()) {
                // User record found, do something with it
                String username = resultSet.getString("username");
                String email = resultSet.getString("email");
                // ...
            } else {
                // User record not found, handle accordingly
            }
            
            // Close the resources
            resultSet.close();
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}