import javax.servlet.ServletRequest;

public class BackupServlet {
    void runBackup(ServletRequest request) {
        // Reference:
        // OWASP Foundation. "Process Control." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Process_Control (retrieved Feb. 21, 2024).
        String btype = request.getParameter("backuptype");
        String cmd = new String("cmd.exe /K \"c:\\util\\rmanDB.bat "+btype+"&&c:\\utl\\cleanup.bat\"");
        System.Runtime.getRuntime().exec(cmd);
        // end
    }    
}