#define MAXLEN 1024

void readAndCopyFromFile(FILE *cfgfile) {
    char *secondbuf[MAXLEN];
    char *inputbuf[MAXLEN];
    
    // read from cfgfile using read
    read(cfgfile, inputbuf, MAXLEN);
    
    // copy inputbuf to secondbuf
    strcpy(secondbuf, inputbuf);
}
