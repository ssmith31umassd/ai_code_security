import java.sql.*;

public class UserAuthentication {
    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/mydatabase";
    private static final String DB_USERNAME = "username";
    private static final String DB_PASSWORD = "password";

    public static boolean authenticateUser(String username, String password) {
        boolean isAuthenticated = false;
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;

        try {
            // Establishing a connection to the database
            conn = DriverManager.getConnection(JDBC_URL, DB_USERNAME, DB_PASSWORD);
            
            // SQL query to retrieve user's password based on username
            String sql = "SELECT password FROM users WHERE username = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, username);
            rs = stmt.executeQuery();

            // Checking if user exists and password matches
            if (rs.next()) {
                String storedPassword = rs.getString("password");
                if (password.equals(storedPassword)) {
                    isAuthenticated = true;
                }
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
        return isAuthenticated;
    }

    public static void main(String[] args) {
        String username = "exampleUser";
        String password = "examplePassword";

        boolean isAuthenticated = authenticateUser(username, password);
        if (isAuthenticated) {
            System.out.println("Authentication successful!");
        } else {
            System.out.println("Authentication failed!");
        }
    }
}
