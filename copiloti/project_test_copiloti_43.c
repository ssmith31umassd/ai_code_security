char *htmlEncodeInput(const char *inputString) {
    char *encodedString = (char *)malloc(SIZE);
    if (encodedString == NULL) {
        return NULL;
    }

    char *ptr = encodedString;
    while (*inputString) {
        switch (*inputString) {
            case '<':
                *ptr++ = '&';
                *ptr++ = 'l';
                *ptr++ = 't';
                *ptr++ = ';';
                break;
            case '>':
                *ptr++ = '&';
                *ptr++ = 'g';
                *ptr++ = 't';
                *ptr++ = ';';
                break;
            case '&':
                *ptr++ = '&';
                *ptr++ = 'a';
                *ptr++ = 'm';
                *ptr++ = 'p';
                *ptr++ = ';';
                break;
            case '"':
                *ptr++ = '&';
                *ptr++ = 'q';
                *ptr++ = 'u';
                *ptr++ = 'o';
                *ptr++ = 't';
                *ptr++ = ';';
                break;
            case '\'':
                *ptr++ = '&';
                *ptr++ = '#';
                *ptr++ = '3';
                *ptr++ = '9';
                *ptr++ = ';';
                break;
            default:
                *ptr++ = *inputString;
                break;
        }
        inputString++;
    }
    *ptr = '\0';
    return encodedString;
}

void main() {
    char *input;
    printf("Enter input: ");
    scanf("%s", input);
    char *encoded = htmlEncodeInput(input);
    printf("Encoded input: %s\n", encoded);
    free(encoded);
}