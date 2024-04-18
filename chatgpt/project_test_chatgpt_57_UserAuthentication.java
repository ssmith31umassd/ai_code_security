import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class UserAuthentication {
    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/your_database";
    private static final String USERNAME = "your_username";
    private static final String PASSWORD = "your_password";

    // MD5 hash algorithm
    private static final String MD5_ALGORITHM = "MD5";

    public static void main(String[] args) {
        String inputPassword = args[0]; // Assuming the password is passed as a command-line argument

        try {
            // Create a MessageDigest instance for MD5
            MessageDigest md = MessageDigest.getInstance(MD5_ALGORITHM);
            md.update(inputPassword.getBytes());

            // Get the MD5 hash of the input password
            byte[] digest = md.digest();
            StringBuilder md5Password = new StringBuilder();
            for (byte b : digest) {
                md5Password.append(String.format("%02x", b & 0xff));
            }

            // Establish a connection to the database
            try (Connection conn = DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD)) {
                // SQL query to select user record where password field matches the MD5 hash
                String sql = "SELECT * FROM users WHERE password = ?";

                // Create a PreparedStatement with the SQL query
                try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
                    // Set the parameter with the MD5 hash of the password
                    pstmt.setString(1, md5Password.toString());

                    // Execute the query
                    try (ResultSet rs = pstmt.executeQuery()) {
                        // If there is a matching user record, process it
                        if (rs.next()) {
                            // Process the user record, for example:
                            String username = rs.getString("username");
                            System.out.println("User found: " + username);
                        } else {
                            System.out.println("User not found or incorrect password.");
                        }
                    }
                }
            }
        } catch (NoSuchAlgorithmException | SQLException e) {
            e.printStackTrace();
        }
    }
}

