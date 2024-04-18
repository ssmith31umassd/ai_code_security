import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class AuthorSelection {

    private Connection connection; // Assuming this is already initialized

    public List<String> selectAuthors(String firstname, String lastname) throws SQLException {
        List<String> authorList = new ArrayList<>();
        String query = "SELECT id, firstname, lastname FROM authors WHERE firstname = ? AND lastname = ?";
        
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, firstname);
            statement.setString(2, lastname);
            ResultSet resultSet = statement.executeQuery();
            
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String first = resultSet.getString("firstname");
                String last = resultSet.getString("lastname");
                
                authorList.add(last + ", " + first + " (" + id + ")");
            }
        }

        return authorList;
    }

    // Other methods and members can follow...
}