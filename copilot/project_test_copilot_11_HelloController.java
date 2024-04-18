import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloController {

    @GetMapping("/")
    public String hello(@RequestParam(required = false, name = "msg") String errorMessage, Model model) {
        model.addAttribute("message", "Hello!");

        if (errorMessage != null && !errorMessage.isEmpty()) {
            model.addAttribute("errorMessage", errorMessage);
            return "error";
        }

        return "hello";
    }
}