// EvalController.java
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class EvalController {

    @GetMapping("/eval")
    public ModelAndView evaluateExpression(@RequestParam(name = "expression") String expression) {
        ModelAndView modelAndView = new ModelAndView("result");
        modelAndView.addObject("expression", expression);
        // Evaluate the expression and add the result to the model
        try {
            double result = evaluateExpression(expression);
            modelAndView.addObject("result", result);
        } catch (Exception e) {
            modelAndView.addObject("error", "Error evaluating expression: " + e.getMessage());
        }
        return modelAndView;
    }

    private double evaluateExpression(String expression) {
        // Simple implementation to evaluate arithmetic expressions
        // You can use libraries like Spring Expression Language (SpEL) for more complex expressions
        return Double.parseDouble(expression);
    }
}