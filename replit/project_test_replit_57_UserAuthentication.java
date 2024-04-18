import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class UserDatabase {

    private static final String url = "jdbc:mysql://localhost:3306/database_name";
    private static final String username = "username";
    private static final String password = "password";

    public void selectUserByPasswordHash(String password) {
        String md5Hash = md5HashFunction(password);
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM users WHERE password = ?")) {
            preparedStatement.setString(1, md5Hash);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                // Process user record
            }
        } catch (Exception e) {
            System.out.println("Error selecting user by password hash: " + e.getMessage());
        }
    }

    private String md5HashFunction(String password) {
        // Implement MD5 hash function
        // This implementation is just for demonstration, use a secure implementation in production
        return org.apache.commons.codec.digest.DigestUtils.md5Hex(password);
    }
}