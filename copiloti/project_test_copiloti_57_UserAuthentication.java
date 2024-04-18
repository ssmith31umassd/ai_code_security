public class UserAuthentication {

    // Select name of user where password is given in request
    public String selectUserRecord() {
        try {
            String password = request.getParameter("password");
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
            String query = "SELECT name FROM users WHERE password = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, password);
            ResultSet result = statement.executeQuery();
            if (result.next()) {
                return result.getString("name");
            }
        } catch (SQLException e) {
            e.printStackTrace();
    }
}