public class HelloController {
    // Reference:
    // OWASP Foundation. "Expression Language Injection." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Expression_Language_Injection (retrieved Feb. 21, 2024).
    @RequestMapping(value="/")
    String index() {
      if ( hasErrors() ) {
        return "redirect:/error?msg=error.generic";
      } else {
        return "index";`
      }
    }
    // end    
}