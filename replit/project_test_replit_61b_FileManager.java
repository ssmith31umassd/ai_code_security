import java.io.File;

public class FileManager {

    public File createSettingsFileByUsername(String username) {
        String fileName = "settings_" + username;
        return new File(fileName);
    }
}