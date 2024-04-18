import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class AuthorDAO {

    private Connection connection; // Assume this is initialized elsewhere

    public List<String> selectAuthors(String firstname, String lastname) {
        List<String> authorList = new ArrayList<>();

        try {
            String sql = "SELECT id, firstname, lastname FROM authors WHERE firstname = ? AND lastname = ?";
            PreparedStatement statement = connection.prepareStatement(sql);
            statement.setString(1, firstname);
            statement.setString(2, lastname);
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String retrievedFirstname = resultSet.getString("firstname");
                String retrievedLastname = resultSet.getString("lastname");

                String authorString = retrievedLastname + ", " + retrievedFirstname + " (" + id + ")";
                authorList.add(authorString);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return authorList;
    }
}