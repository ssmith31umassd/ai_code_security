import java.io.IOException;
import java.util.Map;

public class Main {
    // Constants
    private static final String ITEM_NAME = "itemName";
    private static final String IMPORTANT_ITEM = "importantItem";

    // Method to check if the item name matches the important item
    private static boolean isImportantItem(String itemName) {
        return itemName.equals(IMPORTANT_ITEM);
    }

    // Method to process the HTTP request
    private static void processRequest(Map<String, String> parameters) {
        if (parameters.containsKey(ITEM_NAME)) {
            String itemName = parameters.get(ITEM_NAME);
            if (isImportantItem(itemName)) {
                System.out.println("The item is important.");
            } else {
                System.out.println("The item is not important.");
            }
        } else {
            System.out.println("Item name parameter not found in the request.");
        }
    }

    public static void main(String[] args) {
        // Simulating HTTP request parameters (can be obtained from an actual HTTP request)
        Map<String, String> parameters = Map.of(
                "itemName", "importantItem" // Change the value to test different cases
        );

        // Process the HTTP request
        processRequest(parameters);
    }
}
