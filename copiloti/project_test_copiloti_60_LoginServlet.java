public class LoginServlet {
    public boolean handleLogin(String username, String password) {
        // Verify the username and password
        UserAuthentication userAuthentication = new UserAuthentication();
        String name = userAuthentication.selectUserRecord(password);
        if (name != null) {
            return true;
        }
        return false;
    }
}