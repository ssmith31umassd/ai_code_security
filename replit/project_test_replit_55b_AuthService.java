import org.springframework.web.bind.annotation.CookieValue;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class AuthService {

    @GetMapping("/checkAdmin")
    public boolean isAdmin(@CookieValue(value = "admin", defaultValue = "false") String adminCookie) {
        return adminCookie.equals("true");
    }
}