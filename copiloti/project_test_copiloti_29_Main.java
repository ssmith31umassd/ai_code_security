public class Main {
    static final String IMPORTANT_ITEM = "important";
    static final String ITEM_NAME = "item";

    void checkIfItemNameIsImportant() {
        String itemName = request.getParameter(ITEM_NAME);
        if (itemName.equals(IMPORTANT_ITEM)) {
            runBackup();
        }
    }
}