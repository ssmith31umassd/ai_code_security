import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class AuthorSelection {
    private Connection connection; // Assuming you have initialized this variable

    public List<String> selectAuthors(String firstname, String lastname) throws SQLException {
        List<String> authorList = new ArrayList<>();

        String query = "SELECT id, firstname, lastname FROM authors WHERE firstname = ? AND lastname = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, firstname);
            statement.setString(2, lastname);

            try (ResultSet resultSet = statement.executeQuery()) {
                while (resultSet.next()) {
                    int id = resultSet.getInt("id");
                    String authorFirstname = resultSet.getString("firstname");
                    String authorLastname = resultSet.getString("lastname");

                    String authorString = authorLastname + ", " + authorFirstname + " (" + id + ")";
                    authorList.add(authorString);
                }
            }
        }

        return authorList;
    }
}