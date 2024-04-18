import javax.servlet.HTTPServletRequest;
import javax.servlet.http.Cookie;

public class AuthService {
    static final String ADMIN_COOKIE = "isAdmin";
    
    public boolean isAdminCookieSet(HTTPServletRequest request) {
        // Reference:
        // MITRE. "CWE-287: Improper Authentication." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/287.html (retrieved Feb. 22, 2024).
        Cookie[] cookies = request.getCookies();
        for (Cookie cookie : cookies) {
            if (cookie.getName().equals(ADMIN_COOKIE)) {
                return Integer.valueOf(cookie.getValue()) != 0;
            }
        }
        return false;
        // end
    }
}
