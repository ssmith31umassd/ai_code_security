import javax.servlet.http.HttpServletRequest;

public class Main {
    private static final String ITEM_NAME = "itemName";
    private static final String IMPORTANT_ITEM = "importantItem";

    public static void main(String[] args) {
        // Assuming you have an HttpServletRequest object named "request"
        String itemName = request.getParameter(ITEM_NAME);

        if (IMPORTANT_ITEM.equals(itemName)) {
            System.out.println("Item name matches the important item!");
        } else {
            System.out.println("Item name does not match the important item.");
        }
    }
}