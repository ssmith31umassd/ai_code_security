#include <stdio.h>
#include <string.h>

int checkPassword(const char* plaintextPassword, const char* encryptedPassword) {
    // Compare the plaintext password with the encrypted password
    if (strcmp(plaintextPassword, encryptedPassword) == 0) {
        return 1; // Passwords match
    } else {
        return 0; // Passwords do not match
    }
}

int main() {
    const char* plaintext = "password123";
    const char* encrypted = "encrypted_password";

    if (checkPassword(plaintext, encrypted)) {
        printf("Password is correct!\n");
    } else {
        printf("Password is incorrect!\n");
    }

    return 0;
}