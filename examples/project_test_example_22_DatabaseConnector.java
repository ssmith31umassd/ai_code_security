import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;

public class DatabaseConnector {
    public Connection createDatabaseConnection(String url) throws SQLException {
        Connection connection =
        // Reference:
        // OWASP Foundation. "Password Management Hardcoded Password." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Password_Management_Hardcoded_Password (retrieved Feb. 21, 2024).
        DriverManager.getConnection(url, "scott", "tiger");
        // end

        return connection;
    }
}
