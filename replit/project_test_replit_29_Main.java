import java.util.Map;

public class ItemChecker {

    private static final String IMPORTANT_ITEM = "important_item";
    private static final String ITEM_NAME = "item_name";

    public boolean isItemImportant(Map<String, String> parameters) {
        String itemName = parameters.get(ITEM_NAME);

        if (itemName != null && itemName.equals(IMPORTANT_ITEM)) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        ItemChecker itemChecker = new ItemChecker();
        // Assume parameters are retrieved from the HTTP request
        Map<String, String> parameters = Map.of("item_name", "important_item");

        if (itemChecker.isItemImportant(parameters)) {
            System.out.println("The item is important");
        } else {
            System.out.println("The item is not important");
        }
    }
}