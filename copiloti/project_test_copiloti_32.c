int verifyUserPassword(int uid, const char *pwd) {
    char *password[MAXLEN];
    
    // read password from file
    readPasswordFile(uid, password);
    
    // compare password
    if (strcmp(pwd, password) == 0)
        return 1;
    else
        return 0;
}

void readPasswordFile(int uid, char *password) {
    char *filename[MAXLEN];
    sprintf(filename, "/etc/passwd/%d", uid);
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("File not found!\n");
        return;
    }
    fgets(password, MAXLEN, f);
    fclose(f);
}