char* trimTrailingWhitespace(char *strMessage, int length) {
    while (strMessage[length - 1] == ' ' || strMessage[length - 1] == '\n' || strMessage[length - 1] == '\r') {
        strMessage[length - 1] = '\0';
        length--;
    }
    return strMessage;
}

void main() {
    char *strMessage = (char *)malloc(100);
    int length = 0;
    scanf("%s", strMessage);
    length = strlen(strMessage);
    strMessage = trimTrailingWhitespace(strMessage, length);
    printf("%s\n", strMessage);
    free(strMessage);
}
