public class DirectoryCommandExecutor {
    static final String INITCMD = "init";

    // get home directory from System property APPHOME, then run INITCMD in home directory
    public void executeCommand() {
        String homeDirectory = System.getProperty("APPHOME");
        try {
            ProcessBuilder processBuilder = new ProcessBuilder(homeDirectory + "/" + INITCMD);
            processBuilder.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}