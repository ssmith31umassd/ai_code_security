import java.io.File;

public class MyClass {
    public File createSettingsFile(String username) {
        String filename = "settings_" + username;
        File file = new File(filename);
        return file;
    }
}