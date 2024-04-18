
public class DirectoryCommandExecutor {
    static final String INITCMD = "hello";

    void runCommand() {
        // Reference:
        // OWASP Foundation. "Process Control." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Process_Control (retrieved Feb. 21, 2024).
        String home = System.getProperty("APPHOME");
        String cmd = home + INITCMD;
        java.lang.Runtime.getRuntime().exec(cmd);
        // end
    }
}