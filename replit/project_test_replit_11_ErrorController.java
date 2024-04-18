// ErrorController.java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class ErrorController {
    
    @RequestMapping("/error")
    public ModelAndView handleError(@ModelAttribute("error_msg") String errorMsg) {
        ModelAndView modelAndView = new ModelAndView("error");
        modelAndView.addObject("errorMsg", errorMsg);
        return modelAndView;
    }
}