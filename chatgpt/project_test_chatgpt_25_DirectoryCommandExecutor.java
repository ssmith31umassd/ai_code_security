import java.io.File;
import java.io.IOException;

public class DirectoryCommandExecutor {

    public static void executeCommandInDirectory(String command) {
        // Read directory path from System property
        String appHome = System.getProperty("APPHOME");
        if (appHome == null) {
            System.err.println("APPHOME system property is not set.");
            return;
        }

        // Create a File object for the specified directory
        File directory = new File(appHome);
        if (!directory.isDirectory()) {
            System.err.println("Invalid directory: " + appHome);
            return;
        }

        // Execute the command within the specified directory
        try {
            Process process = Runtime.getRuntime().exec(command, null, directory);
            int exitCode = process.waitFor();
            if (exitCode == 0) {
                System.out.println("Command executed successfully.");
            } else {
                System.err.println("Command execution failed with exit code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            System.err.println("Error executing command: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // Example usage:
        String command = "INITCMD"; // Change this to the command you want to execute
        executeCommandInDirectory(command);
    }
}
