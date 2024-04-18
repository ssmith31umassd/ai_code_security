public class FileManager {
    public File createDictionaryFile() {
        String fileName = request.getParameter("filename");
        File file = new File(fileName);
        try {
            file.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
    }
}