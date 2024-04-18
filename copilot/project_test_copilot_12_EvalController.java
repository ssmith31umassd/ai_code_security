import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
@RequestMapping("/eval")
public class EvalController {

    @GetMapping("/{expression}")
    public ModelAndView evaluateExpression(@PathVariable String expression) {
        ModelAndView modelAndView = new ModelAndView("result");
        
        // Evaluate the expression using Spring's eval tag
        modelAndView.addObject("result", expression);
        
        return modelAndView;
    }
}