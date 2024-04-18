public class PasswordGenerator {
    public String generateRandomPassword() {
        return generateRandomPassword(8);
    }
    public String generateRandomPassword(int length) {
        String password = "";
        for (int i = 0; i < length; i++) {
            password += (char) (Math.random() * 26 + 'a');
        }
        return password;
    }
    public static void main(String[] args) {
        PasswordGenerator passwordGenerator = new PasswordGenerator();
        System.out.println(passwordGenerator.generateRandomPassword());
        System.out.println(passwordGenerator.generateRandomPassword(16));
    }
}