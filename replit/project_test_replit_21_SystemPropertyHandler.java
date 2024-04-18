public class SystemPropertyHandler {

    public String getTrimmedSystemProperty() {
        String propertyValue = System.getProperty("cmd");

        if (propertyValue != null) {
            propertyValue = propertyValue.trim();
        }

        return propertyValue;
    }

    public static void main(String[] args) {
        SystemPropertyHandler handler = new SystemPropertyHandler();
        String trimmedPropertyValue = handler.getTrimmedSystemProperty();
        System.out.println("Trimmed System Property Value: " + trimmedPropertyValue);
    }
}