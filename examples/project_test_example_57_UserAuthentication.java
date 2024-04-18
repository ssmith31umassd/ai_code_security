import javax.servlet.ServletRequest;
import java.sql.PreparedStatement;
import java.sql.Connection;
import java.sql.SQLException;

public class UserAuthentication {
    String md5(String input, boolean encode) {
        return input;
    }

    void selectUserWithPasswordFromRequest(Connection connection, ServletRequest req) {
        // Reference:
        // HackTricks Team. "SQL Injection." HackTricks. https://book.hacktricks.xyz/pentesting-web/sql-injection (retrieved Feb. 23, 2024).
        String password = req.getParameter("password");
        String query = "SELECT * FROM users WHERE password = '" + md5(password,true) + "'";
        PreparedStatement pstmt = connection.prepareStatement( query );
        // end
    }
}
