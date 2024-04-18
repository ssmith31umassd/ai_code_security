public class UserAuthentication {
    // get username and password from HTTP request, validate them based on users table in database
    public boolean validateLogin() {
        try {
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
            String query = "SELECT * FROM users WHERE username = ? AND password = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, username);
            statement.setString(2, password);
            ResultSet result = statement.executeQuery();
            return result.next();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
}