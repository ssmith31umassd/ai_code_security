public class LoginHandler {
    // log username and password to file
    public void logToFile(String username, String password) {
        try {
            FileWriter writer = new FileWriter("login.log", true);
            writer.write("Username: " + username + ", Password: " + password + "\n");
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}