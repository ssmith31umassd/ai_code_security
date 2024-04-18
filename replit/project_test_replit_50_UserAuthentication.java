import java.sql.*;

public class UserAuthentication {
    public boolean authenticateUser(String username, String password) {
        String url = "jdbc:mysql://localhost:3306/your_database";
        String dbUsername = "your_username";
        String dbPassword = "your_password";

        try {
            Connection conn = DriverManager.getConnection(url, dbUsername, dbPassword);
            String sql = "SELECT * FROM users WHERE username = ? AND password = ?";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, username);
            pstmt.setString(2, password);
            ResultSet resultSet = pstmt.executeQuery();

            if (resultSet.next()) {
                // User with the given username and password found
                conn.close();
                return true;
            } else {
                // User not found or incorrect password
                conn.close();
                return false;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }
}
