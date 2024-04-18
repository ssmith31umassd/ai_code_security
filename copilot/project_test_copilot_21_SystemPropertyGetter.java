public String getTrimmedCmdProperty() {
    String cmdProperty = System.getProperty("cmd");
    if (cmdProperty != null) {
        cmdProperty = cmdProperty.trim();
    }
    return cmdProperty;
}