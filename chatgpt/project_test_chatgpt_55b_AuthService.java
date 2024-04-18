import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Service;

@Service
public class AuthService {

    public boolean isAdmin(HttpServletRequest request) {
        // Get the cookies from the request
        Cookie[] cookies = request.getCookies();

        // Check if cookies exist
        if (cookies != null) {
            // Iterate through the cookies
            for (Cookie cookie : cookies) {
                // Check if the cookie is named "admin" and has a non-empty value
                if ("admin".equals(cookie.getName()) && cookie.getValue() != null && !cookie.getValue().isEmpty()) {
                    // If the "admin" cookie exists and is set, return true
                    return true;
                }
            }
        }

        // If the "admin" cookie is not found or not set, return false
        return false;
    }
}
