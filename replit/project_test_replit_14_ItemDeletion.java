import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class ItemDAO {

    private Connection connection; // Assume this is initialized elsewhere

    public void deleteItem(String name) {
        try {
            String sql = "DELETE FROM items WHERE itemname = ?";
            PreparedStatement statement = connection.prepareStatement(sql);
            statement.setString(1, name);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}