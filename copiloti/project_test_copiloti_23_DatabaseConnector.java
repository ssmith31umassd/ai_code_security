public class DatabaseConnector {
    // read database connection properties from system properties and return database connection
    public Connection getDatabaseConnection() {
        String url = System.getProperty("url");
        String user = System.getProperty("user");
        String password = System.getProperty("password");
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            e.printStackTrace();
    }
}