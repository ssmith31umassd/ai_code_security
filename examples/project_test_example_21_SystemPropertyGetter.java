public class SystemPropertyGetter {
    String getCmdProperty() {
        // Reference:
        // OWASP Foundation. "Null Dereference." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Null_Dereference (retrieved Feb. 21, 2024).
        String cmd = System.getProperty("cmd");
        cmd = cmd.trim();
        // end

        return cmd;
    }
}