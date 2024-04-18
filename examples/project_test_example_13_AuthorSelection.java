import javax.servlet.ServletRequest;
import java.sql.Connection;

public class AuthorSelection {
    public void selectAuthors(Connection connection, ServletRequest req) {
        // Reference:
        // OWASP Foundation. "SQL Injection." Attacks. https://owasp.org/www-community/attacks/SQL_Injection (retrieved Feb. 21, 2024).
        String firstname = req.getParameter("firstname");
        String lastname = req.getParameter("lastname");
        String query = "SELECT id, firstname, lastname FROM authors WHERE firstname = '" + firstname + "' and lastname = '" + lastname + "'";
        PreparedStatement pstmt = connection.prepareStatement( query );
        try
        {
            ResultSet results = pstmt.execute( );
        }
        // end
        catch (Exception ex) {}        
    }
}