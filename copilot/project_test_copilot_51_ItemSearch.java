import java.sql.*;
import java.util.HashSet;
import java.util.Set;

public class ItemSearch {
    public Set<String> searchItems(String searchTerm) {
        Set<String> resultSet = new HashSet<>();

        try {
            // Assuming you have a database connection
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
            Statement statement = connection.createStatement();

            // Execute the SQL query
            String sqlQuery = "SELECT * FROM items WHERE description LIKE '%" + searchTerm + "%'";
            ResultSet rs = statement.executeQuery(sqlQuery);

            // Iterate through the result set and add matching records to the set
            while (rs.next()) {
                String description = rs.getString("description");
                resultSet.add(description);
            }

            // Close the database connection
            rs.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return resultSet;
    }
}