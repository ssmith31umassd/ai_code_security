import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class SearchServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String searchTerm = request.getParameter("search");

        // JDBC connection parameters
        String url = "jdbc:mysql://localhost:3306/your_database";
        String username = "your_username";
        String password = "your_password";

        try {
            // Establishing the JDBC connection
            Connection conn = DriverManager.getConnection(url, username, password);

            // SQL query to retrieve records based on the search term
            String sql = "SELECT * FROM items WHERE description LIKE ?";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, "%" + searchTerm + "%");
            ResultSet resultSet = pstmt.executeQuery();

            // Processing the result set
            while(resultSet.next()) {
                // Retrieve and process the records as needed
                String description = resultSet.getString("description");
                // Output the retrieved records
                System.out.println(description);
            }

            // Closing the resources
            resultSet.close();
            pstmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
