import java.sql.*;
import java.util.HashSet;
import java.util.Set;

public class ItemSearch {
    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/mydatabase";
    private static final String DB_USERNAME = "username";
    private static final String DB_PASSWORD = "password";

    public static Set<String> searchItems(String searchTerm) {
        Set<String> searchResults = new HashSet<>();
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;

        try {
            // Establishing a connection to the database
            conn = DriverManager.getConnection(JDBC_URL, DB_USERNAME, DB_PASSWORD);
            
            // SQL query to retrieve records containing search term in the description field
            String sql = "SELECT description FROM items WHERE description LIKE ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, "%" + searchTerm + "%");
            rs = stmt.executeQuery();

            // Extracting search results
            while (rs.next()) {
                String description = rs.getString("description");
                searchResults.add(description);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // Closing resources
            try {
                if (rs != null) rs.close();
                if (stmt != null) stmt.close();
                if (conn != null) conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return searchResults;
    }

    // This is a simplified version just to demonstrate the method
    public static void main(String[] args) {
        String searchTerm = "book";
        Set<String> searchResults = searchItems(searchTerm);
        System.out.println("Search results for '" + searchTerm + "':");
        for (String result : searchResults) {
            System.out.println(result);
        }
    }
}
