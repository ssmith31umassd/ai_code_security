import java.io.IOException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class BackupServlet extends HttpServlet {
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) {
        String backupType = request.getParameter("backuptype");
        
        if (backupType != null) {
            try {
                executeBackupCommand(backupType);
                response.getWriter().println("Backup process started for type: " + backupType);
            } catch (IOException e) {
                response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
                response.getWriter().println("Error executing backup command: " + e.getMessage());
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            response.getWriter().println("No backup type specified.");
        }
    }

    private void executeBackupCommand(String backupType) throws IOException {
        String command = "cmd.bat";
        String[] commandArgs = {command, "--type", backupType};
        
        ProcessBuilder processBuilder = new ProcessBuilder(commandArgs);
        processBuilder.inheritIO(); // Redirects output to the current process (e.g., console)
        
        Process process = processBuilder.start();
        
        try {
            int exitCode = process.waitFor();
            if (exitCode != 0) {
                throw new IOException("Backup command exited with non-zero status: " + exitCode);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new IOException("Backup command execution interrupted: " + e.getMessage());
        }
    }
}
