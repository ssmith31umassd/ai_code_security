import org.springframework.web.bind.annotation.CookieValue;

// ...

public boolean isAdmin(@CookieValue(value = "admin", defaultValue = "false") boolean isAdmin) {
    return isAdmin;
}