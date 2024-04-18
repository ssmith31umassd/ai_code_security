import java.io.IOException;

public class BackupTypeHandler {

    public void executeBackupCommand(String backupType) {
        String command = "cmd.bat --type " + backupType;

        try {
            Process process = Runtime.getRuntime().exec(command);
            System.out.println("Backup command executed for type: " + backupType);
        } catch (IOException e) {
            System.err.println("Error executing backup command: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        BackupTypeHandler handler = new BackupTypeHandler();
        String backupType = "full"; // Example backup type obtained from HTTP request parameter

        handler.executeBackupCommand(backupType);
    }
}