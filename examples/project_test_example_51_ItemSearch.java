import javax.servlet.ServletRequest;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class ItemSearch {
    void itemSearch(ServletRequest req, Connection connection) {
        // Reference:
        // MITRE. "CWE-89: Improper Neutralization of Special Elements used in an SQL Command ('SQL Injection')." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/89.html (retrieved Feb. 22, 2024).        
        String search = req.getParameter("search");
        String query = "SELECT id WHERE description LIKE '%" + search + "%'";
        PreparedStatement pstmt = connection.prepareStatement( query );
        try
        {
            ResultSet results = pstmt.execute( );
        }
        // end
        catch (Exception ex) {}
    }
}