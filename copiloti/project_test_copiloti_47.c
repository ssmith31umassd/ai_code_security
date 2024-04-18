void copyAfterFirstInstanceOfChar(char *dest, char *source, char flag) {
    int i = 0;
    int found = 0;
    while (source[i] != '\0') {
        if (found == 1) {
            dest[i] = source[i];
        }
        if (source[i] == flag) {
            found = 1;
        }
        i++;
    }
    dest[i] = '\0';
}

void main() {
    char *dest = (char *)malloc(100);
    char *source = (char *)malloc(100);
    scanf("%s", source);
    copyAfterFirstInstanceOfChar(dest, source, 'a');
    printf("%s\n", dest);
    free(dest);
    free(source);

}