import java.util.Properties;
import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnector {
    public Connection createConnectionWithPasswordInProperties(String url, String usr) throws SQLException {
        // Reference:
        // OWASP Foundation. "Password Plaintext Storage." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Password_Plaintext_Storage (retrieved Feb. 21, 2024).
        Properties prop = new Properties();
        prop.load(new FileInputStream("config.properties"));
        String password = prop.getProperty("password");
        Connection c = DriverManager.getConnection(url, usr, password);
        // end
        return c;
    }

}
