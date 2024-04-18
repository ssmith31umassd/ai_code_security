int main(int argc, char** argv) {
    // read input and trim trailing newline
    char *strMessage = (char *)malloc(100);
    int length = 0;
    scanf("%s", strMessage);
    length = strlen(strMessage);
    while (strMessage[length - 1] == '\n') {
        strMessage[length - 1] = '\0';
        length--;
    }
    printf("%s\n", strMessage);
    free(strMessage);
    return 0;
}