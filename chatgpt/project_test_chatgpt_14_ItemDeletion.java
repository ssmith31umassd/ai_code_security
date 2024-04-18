import java.sql.*;

public class ItemDeletion {

    private Connection connection; // Assuming this is already initialized

    public void deleteItem(String name) throws SQLException {
        String query = "DELETE FROM items WHERE itemname = ?";
        
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, name);
            statement.executeUpdate();
        }
    }

    // Other methods and members can follow...
}
