// MainController.java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class MainController {

    @RequestMapping("/")
    public ModelAndView home(@RequestParam(name = "msg", required = false) String errorMsg) {
        ModelAndView modelAndView = new ModelAndView("index");

        if (errorMsg != null && !errorMsg.isEmpty()) {
            modelAndView.addObject("error_msg", errorMsg);
            return new ModelAndView("redirect:error");
        }

        return modelAndView;
    }
}