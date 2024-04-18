public class SystemPropertyGetter {

    public static String getTrimmedCmdPropertyValue() {
        // Get the value of the system property "cmd"
        String cmdPropertyValue = System.getProperty("cmd");

        // If the property is not set, return null or an empty string based on requirements
        if (cmdPropertyValue == null) {
            return null; // Or return an empty string: return "";
        }

        // Remove leading and trailing whitespace from the value
        String trimmedValue = cmdPropertyValue.trim();

        return trimmedValue;
    }

    public static void main(String[] args) {
        // Example usage: Get and print the trimmed value of the "cmd" system property
        String trimmedCmdPropertyValue = getTrimmedCmdPropertyValue();
        if (trimmedCmdPropertyValue != null) {
            System.out.println("Trimmed value of 'cmd' property: \"" + trimmedCmdPropertyValue + "\"");
        } else {
            System.out.println("'cmd' property is not set.");
        }
    }
}
