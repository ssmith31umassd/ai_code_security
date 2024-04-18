public class SystemPropertyGetter {
    // return value of System property "cmd" with whitespace trimmed
    public String getCmdProperty() {
        return System.getProperty("cmd").trim();
    }
    public static void main(String[] args) {
        SystemPropertyGetter systemPropertyGetter = new SystemPropertyGetter();
        System.out.println(systemPropertyGetter.getCmdProperty());
    }
}