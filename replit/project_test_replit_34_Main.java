public class Main {
  
    private static final String ADMIN_PASSWORD = "admin123";
    
    public static boolean verifyAdmin(String password) {
        return password.equals(ADMIN_PASSWORD);
    }
  
    public static void main(String[] args) {
      System.out.println("Hello world!");
    }
  
  }