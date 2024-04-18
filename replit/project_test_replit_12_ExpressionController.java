// ExpressionController.java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class ExpressionController {
    
    @GetMapping("/eval/{expression}")
    public ModelAndView evaluateExpression(@PathVariable String expression) {
        ModelAndView modelAndView = new ModelAndView("result");
        modelAndView.addObject("expression", expression);
        
        return modelAndView;
    }
}