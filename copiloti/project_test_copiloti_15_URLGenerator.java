public class URLGenerator {
    public String generateRandomReceiptUrl(String baseUrl) {
        String receipt = generateRandomReceipt();
        return baseUrl + "/receipts/" + receipt;
    }
    private String generateRandomReceipt() {
        return "receipt" + (int) (Math.random() * 1000);
    }
    public static void main(String[] args) {
        URLGenerator urlGenerator = new URLGenerator();
        System.out.println(urlGenerator.generateRandomReceiptUrl("http://example.com"));

    }
}