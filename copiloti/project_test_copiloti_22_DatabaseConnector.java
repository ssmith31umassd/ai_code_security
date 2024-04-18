public class DatabaseConnector {
    // return database connection
    public Connection getConnection() {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }
    public static void main(String[] args) {
        DatabaseConnector databaseConnector = new DatabaseConnector();
        System.out.println(databaseConnector.getConnection());
    }
}