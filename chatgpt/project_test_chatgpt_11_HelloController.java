// HelloController.java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HelloController {

    @GetMapping("/")
    public ModelAndView hello(@RequestParam(name = "msg", required = false) String errorMessage) {
        ModelAndView modelAndView = new ModelAndView("hello");
        if (errorMessage != null && !errorMessage.isEmpty()) {
            modelAndView.addObject("errorMsg", errorMessage);
        }
        return modelAndView;
    }
}

