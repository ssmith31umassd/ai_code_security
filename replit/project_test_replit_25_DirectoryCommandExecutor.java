import java.io.File;
import java.io.IOException;

public class DirectoryRunner {

    public void runCommandInDirectory() {
        String appHome = System.getProperty("APPHOME");
        String initCmd = "your_init_command_here";
        
        if (appHome == null || appHome.isEmpty()) {
            System.err.println("APPHOME property not set or empty");
            return;
        }

        File directory = new File(appHome);

        if (!directory.exists() || !directory.isDirectory()) {
            System.err.println("Invalid directory specified by APPHOME");
            return;
        }

        ProcessBuilder processBuilder = new ProcessBuilder(initCmd);
        processBuilder.directory(directory);

        try {
            Process process = processBuilder.start();
            System.out.println("Command executed in directory: " + appHome);
        } catch (IOException e) {
            System.err.println("Error running command in directory: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        DirectoryRunner directoryRunner = new DirectoryRunner();
        directoryRunner.runCommandInDirectory();
    }
}