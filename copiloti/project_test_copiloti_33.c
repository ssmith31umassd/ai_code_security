int verifyAdmin(const char *password) {
    char *adminPassword[MAXLEN];
    readAdminPassword(adminPassword);
    if (strcmp(password, adminPassword) == 0)
        return 1;
    else
        return 0;
}

void readAdminPassword(char *adminPassword) {
    FILE *f = fopen("/etc/passwd/admin", "r");
    if (!f) {
        printf("File not found!\n");
        return;
    }
    fgets(adminPassword, MAXLEN, f);
    fclose(f);
}

void main() {
    char *password[MAXLEN];
    printf("Enter password: ");
    scanf("%s", password);
    if (verifyAdmin(password)) {
        printf("You are an admin!\n");
    }
    else {
        printf("You are not an admin!\n");
    }
}