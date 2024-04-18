public class FileReader {
    private void processFile(String fName) throws FileNotFoundException, IOException
    {
        try (FileInputStream fis = new FileInputStream(fName)) {
            // Do something
        }
    }
    
    public static void main(String[] args) {
        FileReader fr = new FileReader();
        try {
            fr.processFile("file.txt");
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("IO exception");
        }
    }
}