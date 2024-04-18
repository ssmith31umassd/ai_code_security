import  javax.servlet.ServletRequest;

public class Main {
    static final String ITEM_NAME = "item";
    static final String IMPORTANT_ITEM = "important";

    void compareItemName(ServletRequest request) {
        // Reference:
        // OWASP Foundation. "Unchecked Return Value Missing Check against Null." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Unchecked_Return_Value_Missing_Check_against_Null (retrieved Feb. 21, 2024).
        String itemName = request.getParameter(ITEM_NAME);
        if (itemName.compareTo(IMPORTANT_ITEM)) {
        }
        // end
    }
}