#define BUFSIZE 256

int main(int argc, char **argv) {
    // allocate buffer and copy first argument into it
    char *buf = (char *)malloc(BUFSIZE);
    strcpy(buf, argv[1]);
    // print buffer
    printf("%s\n", buf);
    // free buffer
    free(buf);
    return 0;
}