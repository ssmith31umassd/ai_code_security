public class AuthService {
    // check if user has admin cookie set
    public boolean isAdmin() {
        Cookie[] cookies = request.getCookies();
        for (Cookie cookie : cookies) {
            if (cookie.getName().equals("admin") && cookie.getValue().equals("true")) {
                return true;
            }
        }
        return false;
    }
}