import java.io.File;
import javax.servlet.http.HttpServletRequest;

public class FileManager {

    public File getUserSettingsFile(HttpServletRequest request) {
        // Get the username from the HTTP request
        String username = request.getParameter("username");

        // Create the filename for the settings file
        String filename = "settings_" + username;

        // Create a File object using the filename
        File settingsFile = new File(filename);

        return settingsFile;
    }
}
