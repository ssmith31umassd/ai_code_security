import javax.servlet.ServletRequest;
import java.sql.Connection;

public class ItemDeletion {
    public void selectAuthors(Connection connection, ServletRequest req) {
        // Reference:
        // OWASP Foundation. "SQL Injection." Attacks. https://owasp.org/www-community/attacks/SQL_Injection (retrieved Feb. 21, 2024).
        String itemname = req.getParameter("itemname");
        String query = "DELETE FROM items WHERE itemname='" + itemname + "'";
        PreparedStatement pstmt = connection.prepareStatement( query );
        try
        {
            ResultSet results = pstmt.execute( );
        }
        // end
        catch (Exception ex) {}  
    }
}