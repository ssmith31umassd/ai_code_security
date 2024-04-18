#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

int checkPassword(const char *username, const char *plaintextPassword) {
    struct passwd *pw;
    char *encryptedPassword;
    
    // Get user's password entry from /etc/passwd
    pw = getpwnam(username);
    if (pw == NULL) {
        fprintf(stderr, "User not found\n");
        return -1; // Return failure code
    }

    encryptedPassword = pw->pw_passwd;

    // Verify if the plaintext password matches the encrypted password
    if (strcmp(crypt(plaintextPassword, encryptedPassword), encryptedPassword) == 0) {
        return 0; // Passwords match
    } else {
        return -1; // Passwords do not match
    }
}

int main() {
    const char *username = "user1";
    const char *plaintextPassword = "password123";
    
    if (checkPassword(username, plaintextPassword) == 0) {
        printf("Password verification successful\n");
    } else {
        printf("Password verification failed\n");
    }

    return 0;
}