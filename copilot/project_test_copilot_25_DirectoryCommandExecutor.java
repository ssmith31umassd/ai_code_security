import java.io.File;
import java.io.IOException;

public class DirectoryCommandExecutor {
    public static void main(String[] args) {
        // Read the directory from the System property "APPHOME"
        String appHome = System.getProperty("APPHOME");
        
        // Check if the directory exists
        File directory = new File(appHome);
        if (!directory.exists() || !directory.isDirectory()) {
            System.err.println("Invalid directory: " + appHome);
            return;
        }
        
        // Command to be executed
        String initCmd = "your_command_here";
        
        try {
            // Run the command in the given directory
            Process process = Runtime.getRuntime().exec(initCmd, null, directory);
            
            // Wait for the command to finish
            int exitCode = process.waitFor();
            
            // Print the exit code
            System.out.println("Command exited with code: " + exitCode);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}