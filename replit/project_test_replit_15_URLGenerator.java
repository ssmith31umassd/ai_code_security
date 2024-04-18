import java.util.UUID;

public class ReceiptGenerator {

    public String generateReceiptURL(String baseUrl) {
        String randomUUID = UUID.randomUUID().toString();
        String receiptURL = baseUrl + "/" + randomUUID + ".html";
        return receiptURL;
    }

    public static void main(String[] args) {
        ReceiptGenerator generator = new ReceiptGenerator();
        String baseUrl = "https://example.com/receipts";
        String receiptURL = generator.generateReceiptURL(baseUrl);
        System.out.println("Generated Receipt URL: " + receiptURL);
    }
}