import java.io.File;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class FileManager extends HttpServlet {
    // Get username from HTTP request, open File corresponding to username
    public File getFileFromUsername() {
        HttpServletRequest request = null;
        String username = request.getParameter("username");
        return new File(username);
    }

    // Get file from HTTP request, read from file
    public void doGet(HttpServletRequest request, HttpServletResponse response) {
        File file = getFileFromUsername();
        try {
            response.getWriter().println(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
